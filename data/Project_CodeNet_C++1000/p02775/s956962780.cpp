#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  ll l=s.length(),ans=0;
  lvector v(l,0);
  rep(i,l) v[i]=s[i]-'0';
  reverse(ALL(v));
  rep(i,3) v.emplace_back(0);
  rep(pos,l+1) {
    ll d=v[pos],e=v[pos+1]+1;
    ll num1=10-d+min(e,10ll-e);e--;
    ll num2=d+min(e,10ll-e);
    if(num1<=num2) {ans+=10-d;;v[pos+1]++;}
    else ans+=d;
  }
  print(ans);
  return 0;
}