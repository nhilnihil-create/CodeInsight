#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
int main() {
  int N, M;
  string S;
  cin >> N >> M >> S;
  vector<int> next(N+1, -1);
  set<pair<int, int> > se, se2;
  se.insert(make_pair(0, N));
  se2.insert(make_pair(N, 0));
  rrep(i, N+1) {
    if(S[i] == '1') continue;
    auto begin = se2.lower_bound(make_pair(i+M+1, -1));
    for(auto itr=begin; itr!=se2.end(); itr++) {
      se.erase(make_pair(itr->second, itr->first));
    }
    se2.erase(begin, se2.end());
    int x = se.begin()->first;
    next[i] = se.begin()->second;
    se.insert(make_pair(x+1, i));
    se2.insert(make_pair(i, x+1));
  }
  int tmp = 0;
  vector<int> ans;
  int cnt = 0;
  while(tmp != N) {
    if(next[tmp] == -1 || next[tmp] == tmp || cnt > N) break;
    ans.push_back(next[tmp] - tmp);
    tmp = next[tmp];
    cnt++;
  }
  if(tmp != N) cout << -1 << endl;
  else {
    for(int a: ans) cout << a << ' ';
    cout << endl;
  }
  return 0;
}
