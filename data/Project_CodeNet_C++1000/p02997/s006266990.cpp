#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,k;cin>>n>>k;

  if(k>(n-1)*(n-2)/2) { cout<<-1<<endl; return 0; }

  vector<pi>result;
  rep(i, n-1)result.push_back({1, 2+i});

  int counter = (n-1)*(n-2)/2;
  for(int i=2;i<=n;i++)for(int j=i+1;j<=n;j++){
    if(counter==k)break;
    result.push_back({i, j});
    counter--;
  }

  cout<<result.size()<<endl;
  for(auto p: result)cout<<p.first<<' '<<p.second<<endl;

  return 0;
}