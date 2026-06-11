/**
*    author:  yuya1234
*    created: 15.07.2020 11:57:59
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

  string s;
  ll k;
  cin>>s>>k;

  ll cnt=1,sum=0;
  REP(i,SZ(s)-1)
  {
    if(s[i]==s[i+1])cnt++;
    else 
    {
      sum+=cnt/2;
      cnt=1;
    }
  }
  sum+=cnt/2;

  ll cnt1=1;
  REP(i,SZ(s)-1)
  {
    if(s[i]==s[i+1])cnt1++;
    else break;
  }

  if(SZ(s)==cnt) cout<<k*(ll)s.size()/2<<endl;
  else if(s[SZ(s)-1]!=s[0]) cout<<k*sum<<endl;
  else cout<<sum*k-(cnt/2+cnt1/2-(cnt+cnt1)/2)*(k-1)<<endl;

  return 0;
}