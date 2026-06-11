/**
*    author:  yuya1234
*    created: 10.07.2020 16:58:58
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

  int n;
  cin>>n;

  vector<pair<int,int>> pairs(n);
  int tmp1,tmp2;
  REP(i,n)
  {
    cin>>tmp1>>tmp2;
    pairs[i]=make_pair(tmp2,tmp1);
  }

  SORT(pairs);

  ll sum=0;
  string ans="Yes";
  REP(i,n)
  {
    sum+=pairs[i].second;
    if(sum>pairs[i].first)ans="No";
  }

  cout<<ans<<endl;
  
  return 0;
}