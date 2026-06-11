#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w,a,b;cin>>h>>w>>a>>b;
  rep(i,b) {
    rep(j,a) printf("1");
    rep(j,w-a-1) printf("0");
    printf("0\n");
  }
  rep(i,h-b) {
    rep(j,a) printf("0");
    rep(j,w-a-1) printf("1");
    printf("1\n");
  }
  return 0;
}