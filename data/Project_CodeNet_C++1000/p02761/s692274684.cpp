/**
*    author:  yuya1234
*    created: 09.07.2020 13:00:32
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

  int n,m;
  cin>>n>>m;

  int a[n];
  MEMSET(a,-1);

  int flg=true;
  REP(i,m)
  {
    int s,c;
    cin>>s>>c;

    if(a[s-1]==-1)a[s-1]=c;
    else if(a[s-1]!=c)
    {
      flg=false;
      break;
    }
  }

  if(flg && n==1 && a[0]<=0)
  {
    cout<<0<<endl;
  }
  else if(flg && a[0]!=0)
  {
    REP(i,n)
    {
      if(i==0)
      {
        if(a[i]==-1)cout<<1;
        else cout<<a[i];
      }
      else
      {
        if(a[i]==-1)cout<<0;
        else cout<<a[i];
      }
    }
    cout<<endl;
  }
  else cout<<-1<<endl;

  return 0;
}