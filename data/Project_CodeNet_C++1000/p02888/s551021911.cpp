#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;
vector<int> a;


// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(){
  int N,ans=0;
  cin>>N;
  REP(i,N){
    int s;
    cin>>s;
    a.push_back(s);
  }
  SORT(a);
  
  for(int i=0; i<N-2; ++i){
    for(int j=i+1; j<N-1; ++j){
      ans+=binary_search(a.at(i)+a.at(j))-j-1;
    }
  }
  
  cout<<ans<<endl;
}
