#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPll(i, n) for (decltype(n) i = 0; i < n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007 //1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool> vecbool;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef vector<string> vecstr;
typedef vector<vecint> vec2int;
typedef vector<vecbool> vec2bool;
int dx[4]{-1, +1, 0, 0};
int dy[4]{0, 0, -1, +1};
//////////////////////////////////////////
int main()
{
    int n; cin >> n;
  vector<pair<ll, ll> > v(n);
  for(auto&e: v) cin >> e.first >> e.second;
  vector<vector<pair<ll, ll> > > g(n, vector<pair<ll, ll>>(n));
  map<pair<ll, ll>,int > mp;
  REP(i,n){
    REP(j,n){
      if(i == j) continue;
      g[i][j] = make_pair(v[i].first - v[j].first, v[i].second -v[j].second);
      mp[g[i][j]]++;
    }
  }
  int maxnum = 0;
  REPvec(itr,mp){
    // cout << itr->first.first << " " << itr->first.second << endl;
    maxnum = max(itr->second,maxnum);
  }
  

  // sort(all(v));
  // // for(auto e: v) cout << e.first << " " << e.second << endl;
  // int ans = n;
  // for(int i = 0; i < n; i ++){
  //   for(int j = i + 1; j < n; j ++){
  //     ll p = v[j].first - v[i].first;
  //     ll q = v[j].second - v[i].second;
  //     int now = 1;
  //     for(int k = 1; k < n ; k ++){
  //       if(v[k].first - v[k - 1].first == p&&v[k].second - v[k - 1].second == q){
          
  //       }else{
  //         now ++;
  //       }
  //     }
  //     ans = min(now, ans);
  //   }
  // }
  cout << n - maxnum<< endl;
}