/**
*    author:  yuya1234
*    created: 07.07.2020 15:37:55
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s;
  cin>>s;

  ll ans=0;
  int ss[SZ(s)+1];
  MEMSET(ss,0);

  REP(i,SZ(s))
  {
    if(s[i]=='<')ss[i+1]=max(ss[i+1],ss[i]+1);
  }

  REPD(i,SZ(s))
  {
     if(s[i]=='>')ss[i]=max(ss[i],ss[i+1]+1);
  }

  REP(i,SZ(s)+1)ans+=ss[i];
  cout<<ans<<endl;

  return 0;
}