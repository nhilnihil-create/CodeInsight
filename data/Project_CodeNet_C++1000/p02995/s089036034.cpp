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
  ll a,b,c,d;cin>>a>>b>>c>>d;
  ll e=c*d/__gcd(c,d);
  ll ans=b-a+1-b/c+(a-1)/c-b/d+(a-1)/d+b/e-(a-1)/e;
  print(ans);
  return 0;
}