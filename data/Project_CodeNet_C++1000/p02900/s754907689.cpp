#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


const ll INF = 1e18;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  ll a, b;
  cin >> a >> b;
  ll g=gcd(a,b);
  if (g==1){
    cout<<1;
    return 0;
  }
  vector<P> f;
  ll G=g;
  for(ll i=2;i*i<=G;i++){
  //  cout<<i<<'i'<<G<<'G'<<endl;
    ll cnt=0;
    while(g%i==0){
      cnt++;
      g/=i;
    }
    if (cnt>0){
      f.push_back(make_pair(i,cnt));
  //    cout<<i<<'i'<<cnt<<'c'<<endl;

    }
  }
  if (g>1) f.push_back(make_pair(g,1));
  ll ans=0;
  ans+=f.size();
  ans++;
  cout<<ans;
}
