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
  ll n,x,l;cin>>n>>x;
  lvector L(n+1,0);rep(i,n) {cin>>l;L[i+1]+=L[i]+l;}
  ll ans=n+1;
  rep(i,n+1) if(L[i]>x) {ans=i;break;}
  print(ans);
  return 0;
}