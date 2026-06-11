/**
*    author:  yuya1234
*    created: 17.07.2020 11:06:30
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long double eps = 1.0E-14;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a,T b){return gcd(a,b)*(a/gcd(a,b))*(b/gcd(a,b));}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  ll n;
  cin>>n;

  vector<ll> v;
  ll tmp;
  REP(i,n)
  {
    cin>>tmp;
    v.emplace_back(tmp);
  }
  SORT(v);
  vector<ll> vv;
  vv=v;
  UNIQUE(vv);
  
  ll a[SZ(vv)];
  MEMSET(a,0);

  a[0]++;
  ll idx=0;
  FOR(i,1,n-1)
  {
    if(v[i-1]==v[i])a[idx]++;
    else a[++idx]++;
  }

  string ans="No";

  if(SZ(vv)==1)
  {
    if((vv[0]^vv[0]^vv[0])==0)ans="Yes";
  }
  else if(SZ(vv)==2)
  {
    if((vv[1]^vv[0]^vv[1])==0 && vv[0]==0 && a[0]*3==n && a[1]*3==2*n)ans="Yes";
  }
  else if(SZ(vv)==3)
  {
    if((vv[0]^vv[2]^vv[1])==0 && a[0]*3==n && a[1]*3==n && a[2]*3==n)ans="Yes";
  }
  
  cout<<ans<<endl;

  return 0;
}
