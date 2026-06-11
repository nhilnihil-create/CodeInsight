#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n; cin >> n;
  map<string,int> mp;
  string tmp;
  int count = 0;
  REP(i,n){
    cin >> tmp;
    mp[tmp]++;
    count = max(count,mp[tmp]);
  }
  for(auto itr = mp.begin(); itr != mp.end(); ++itr){
    if(itr->second == count)
      std::cout << itr->first << endl;
  }
}