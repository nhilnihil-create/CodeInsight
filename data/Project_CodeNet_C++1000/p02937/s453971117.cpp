#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<ll,ll>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int main(){

  string s;
  cin >> s;
  string t;
  cin >> t;

  int N=sz(s), M=sz(t);
  vector<vector<int>> is(26);

  rep(i, N) is[s[i]-'a'].push_back(i);
  rep(i, N) is[s[i]-'a'].push_back(i+N);

  ll ans = 0;
  int p = 0;

  rep(i, M){
    int c = t[i] - 'a';
    if(sz(is[c]) == 0){
      cout << -1 << endl;
      return 0;
    } 
    p = *lower_bound(is[c].begin(), is[c].end(), p) + 1;
    if(p >= N){
      ans += N;
      p -= N;
    }
  }
  ans += p;
  cout << ans << endl;
  return 0;
}
