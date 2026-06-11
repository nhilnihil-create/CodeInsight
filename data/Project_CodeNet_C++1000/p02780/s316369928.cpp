/**
*    author:  yuya1234
*    created: 09.07.2020 14:20:24
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

  int n,k;
  cin>>n>>k;

  int p[n];

  REP(i,n)
  {
    cin>>p[i];
  }

  double ans=0,sum=0;
  REP(i,k)
  {
    sum+=(0.5*p[i]*(1+p[i]))/p[i];
  }
  ans=sum;

  FOR(i,1,n-k)
  {
    sum-=(0.5*p[i-1]*(1+p[i-1]))/p[i-1];
    sum+=(0.5*p[i+k-1]*(1+p[i+k-1]))/p[i+k-1];
    ans=max(ans,sum);
  }

  printf("%.12lf\n",ans);

  return 0;
}