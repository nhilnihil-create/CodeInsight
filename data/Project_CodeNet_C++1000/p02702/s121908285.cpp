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
  string s;cin>>s;
  map<ll,ll> mp;
  ll ans=0,powten=10,n=s.length(),val=s[n-1]-'0';
  mp[val]++;mp[0]++;
  for(ll pos=n-2;pos>-1;--pos) {
    powten%=2019;
    val=(s[pos]-'0')*powten+val;
    mp[val%2019]++;
    powten*=10;
  }
  for(auto p:mp) ans+=p.second*(p.second-1)/2;
  print(ans);
  return 0;
}