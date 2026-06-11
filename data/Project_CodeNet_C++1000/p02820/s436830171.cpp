/**
*    author:  yuya1234
*    created: 14.07.2020 16:09:33
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

int r,s,p;
int calc(char pl, char n)
{
  if(pl=='r' && n=='s')return r;
  else if(pl=='s' && n=='p')return s;
  else if(pl=='p' && n=='r')return p;
  else return 0;
}

char calc2(char pre, char n, char next)
{
  if(pre=='r')
  {
    if(n=='r')return 'p';
    else if(n=='p')return 's';
    else if(next=='r') return 's';
    else return 'p';
  }
  else if(pre=='s')
  {
    if(n=='s')return 'r';
    else if(n=='r')return 'p';
    else if(next=='s') return 'p';
    else return 'r';
  }
  else if(pre=='p')
  {
    if(n=='p')return 's';
    else if(n=='s')return 'r';
    else if(next=='p') return 'r';
    else return 's';
  }
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  int n,k;
  cin>>n>>k>>r>>s>>p;

  string t;
  cin>>t;

  char mae[n];
  ll ans=0;
  REP(i,k)
  {
    if(t[i]=='r')
    {
      ans+=p;
      mae[i]='p';
    }
    else if(t[i]=='s')
    {
      ans+=r;
      mae[i]='r';
    }
    else{
      ans+=s;
      mae[i]='s';
    }
  }

  FOR(i,k,n-1-k)
  {
    char pl=calc2(mae[i-k],t[i],t[i+k]);
    if(pl=='r')
    {
      ans+=calc('r',t[i]);
      mae[i]='r';
    }
    else if(pl=='s')
    {
      ans+=calc('s',t[i]);
      mae[i]='s';
    }
    else
    {
      ans+=calc('p',t[i]);
      mae[i]='p';
    }
  }

  FOR(i,n-k,n-1)
  {
    if(mae[i-k]=='r')
    {
      if(calc('p',t[i])>calc('s',t[i]))ans+=calc('p',t[i]);
      else ans+=calc('s',t[i]);
    }
    else if(mae[i-k]=='s')
    {
      if(calc('p',t[i])>calc('r',t[i]))ans+=calc('p',t[i]);
      else ans+=calc('r',t[i]);
    }
     else if(mae[i-k]=='p')
    {
      if(calc('r',t[i])>calc('s',t[i]))ans+=calc('r',t[i]);
      else ans+=calc('s',t[i]);
    }
  }

cout<<ans<<endl;

  return 0;
}