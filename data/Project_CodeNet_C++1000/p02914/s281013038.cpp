// 1 << i と pow(2,i) がi>32のときに死んだ

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<bits/stdc++.h>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long
//#define lint long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
int a[200000];
int keta[80];
int keta2[80];
int l;
int b2[200000];
// Number of bits to
// represent int

int mypow(int _x, int _n){
	int ret = 1;
	while(0 < _n){
		if((_n % 2) == 0){
			_x *= _x;
			_n >>= 1;
		}
		else{
			ret *= _x;
			--_n;
		}
	}
	return ret;
}

// Function to return
// maximum XOR subset
// in set[]
int maxSubarrayXOR(int set[], int n,int l2){
  int index = 0;
  for (int i = l2-1; i >= 0; i--){
    int maxInd = index;
    int maxEle =  -10;
    for (int j = index; j < n; j++) {
      if ( (set[j] & (mypow(2,i))) != 0 && set[j] > maxEle ){
        maxEle = set[j], maxInd = j;
        //cout << (set[j] & (mypow(2,i))) << endl;
      }
    }

    if (maxEle ==  -10) continue;

    swap(set[index], set[maxInd]);

    maxInd = index;

    for (int j=0; j<n; j++){

      if (j != maxInd &&(set[j] & (mypow(2,i))) != 0){
        set[j] = set[j] ^ set[maxInd];
      }
    }
    index++;
  }

  int res = 0;
  for (int i = 0; i < n; i++) res ^= set[i];
  return res;
}




signed main(){
  int n;

  int su = 0;
  int ma = -INF;
  cin >> n;
  REP(i,n){
    cin >> a[i];
    su ^= a[i];
    ma = max(ma,a[i]);
  }
  int l = 0;
  while(ma>0){
    l++;
    ma/=2;
  }
  REP(i,n){
    int no = a[i];
    int kai2 = 0;
    while(no>0){
      keta[kai2] += no%2;
      no/=2;
      kai2 ++;
    }
  }
  int su2 = su;
  int kai3 = 0;
  while(su2>0){
    keta2[kai3] += su2%2;
    su2/=2;
    kai3 ++;
  }
  int ans = su;

  REP(i,n){
    int no3 = a[i];
    int kai4 = 0;
    int ketaa = 0;
    while(no3>0){
      //if(i==0) dump(no3%2);
      if(keta2[kai4]==0){
        int kee = no3%2;
        ketaa += kee*mypow(2,kai4);
        if(i==0){
          //dump(ketaa);
          //dump(kee*mypow(2,kai4));
        }
      }
      no3/=2;
      kai4 ++;
    }
    b2[i] = ketaa;
  }
  //cout << "su=" << bitset<65>(su) << endl;
  REP(i,n){
    //cout << "ai="<<bitset<65>(a[i]) << endl;
    //cout << "bi="<<bitset<64>(b2[i]) << endl;
  }
  //dump(ans);
  ans += 2* maxSubarrayXOR(b2,n,64);
  //dump(l);
  //cout << "   "<<bitset<65>(2012721721873704572-ans) << endl;
  cout << ans << endl;
  return 0;
}
