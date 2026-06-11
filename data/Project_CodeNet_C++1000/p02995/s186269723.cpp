#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(int a,int b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(int a,int b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {//   4 5 6 7 8 9
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll cntc=b/c-(a-1)/c;
  ll cntd=b/d-(a-1)/d;
  ll cntcd=b/(lcm(c,d))-(a-1)/(lcm(c,d));
  ll cnt=cntc+cntd-cntcd;
  ll ans=b-a+1-cnt;
  cout<<ans<<endl;
}