/**
*    author:  yuya1234
*    created: 10.07.2020 16:09:36
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

  double w,h,x,y;
  cin>>w>>h>>x>>y;

  double sum1,sum2,ans=0;
  int cnt=0;

  if(w!=x)
  {
    sum1=(w-x)*h;
    sum2=x*h;
    ans=min(sum1,sum2);
  }

  if(h!=y)
  {
    sum1=(h-y)*w;
    sum2=y*w;
    if(ans==min(sum1,sum2))cnt=1;
    ans=max(ans,min(sum1,sum2));
  }

  if(ans==h*w/2 && cnt==1)cnt=1;
  else cnt=0;
  ans=max(ans,h*w/2);

  printf("%.6lf %d\n",ans,cnt);

  return 0;
}