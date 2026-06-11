#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a ;
        a = a * a ;
        n >>= 1;
    }
    return res;
}

int main(){
  int k;
  cin >> k;
  vector<ll> d[10];
  rep(i, 10){
    d[i].push_back(i);
    if(i!=0){
      k--;
      if(k==0){
        cout<< i<< endl;
        return 0;
      }
    }
  }
  ll digit=1;
  while(k!=0){
    vector<ll> nd[10];
    rep(i, 10){
      for(int j=-1;j<=1; j++){
        if(i+j<0 || i+j>=10)continue;
        int dsz=d[i+j].size();
        rep(l, dsz){
          nd[i].push_back(d[i+j][l]+i*modpow(10, digit));
          if(i!=0){
            k--;
            if(k==0){
              cout<< d[i+j][l]+i*modpow(10, digit)<< endl;
              return 0;
            }
          }
        }
      }
    }
    swap(nd, d);
    digit++;
  }

  return 0;
}
