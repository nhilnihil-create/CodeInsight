#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,u,v,ans=0;cin>>n;
  rep(i,n) ans+=(i+1)*(n-i);
  rep(i,n-1) {
    cin>>u>>v;
    if(u>v) swap(u,v);
    ans-=u*(n-v+1);
  }
  print(ans);
  return 0;
}