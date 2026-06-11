/**
*    author:  yuya1234
*    created: 10.07.2020 16:33:27
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll l,r;
  cin>>l>>r;

  ll ans=2019;
  FOR(i,l,r-1)
  {
    FOR(j,i+1,r)
    {
      ans=min(ans,(i*j)%2019);
      if(ans==0)
      {
        i=r;
        j=r;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}