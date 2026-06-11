#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
typedef long long int ll;
using namespace std;

int main()
{
  int n,k;
  cin >> n >> k;
  int k2 = (n-1)*(n-2)/2;
  if(k > k2){
    cout << "-1\n";
    return 0;
  }
  
  vector<pair<int, int>> ans;
  FOR(i,1,n) ans.emplace_back(0, i);
  
  FOR(i,1,n) FOR(j,i+1,n){
    if(k2==k) break;
    ans.emplace_back(i,j);
    k2--;
  }
  cout << ans.size() << '\n';
  for(auto p: ans) cout << p.first+1 << " " << p.second+1 << '\n';
  return 0;
}