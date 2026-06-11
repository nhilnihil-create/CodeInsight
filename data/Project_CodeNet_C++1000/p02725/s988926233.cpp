#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int k, n;
  cin >> k >> n;
  int bf = -1;
  vector<int> d(n);
  int fr = -1;
  rep(i, n){
    int a;
    cin >> a;
    if(i != 0){
      d.at(i-1) = a - bf;
    }else{
      fr = a;
    }
    bf = a;
  }
  d.at(n-1) = k - bf + fr;
  int mx = 0;
  rep(i, n){
    // cerr << d.at(i) << endl;
    mx = max(mx, d.at(i));
  }
  cout << k - mx << endl;
  return 0;
}