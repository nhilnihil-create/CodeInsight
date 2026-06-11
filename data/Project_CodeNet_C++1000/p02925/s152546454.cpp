#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORr(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  
  vector<vector<int>> a(n, vector<int>(n-1));
  REP(i, n){
    REP(j, n-1){
      cin >> a[i][j];
      a[i][j]--;
    }
    reverse(ALL(a[i]));
  }

  vector<P> q;
  auto check = [&](int i){
    if(a[i].size() == 0) return;
    int j = a[i].back();
    if(a[j].size() == 0) return;
    if(a[j].back() == i){
      if(j < i) swap(i, j); 
      q.emplace_back(P(i, j));
    }
  };
  REP(i, n){
    check(i);
  }
  int day = 0;
  while(q.size() > 0){
    day++;
    sort(ALL(q));
    q.erase(unique(ALL(q)), q.end());
    vector<P> prevQ;
    swap(prevQ, q);
    for(P p : prevQ){
      int i = p.first;
      int j = p.second;
      a[i].pop_back();
      a[j].pop_back();
    }
    for(P p : prevQ){
      int i = p.first;
      int j = p.second;
      check(i);
      check(j);
    }
  }

  REP(i, n){
    if(a[i].size() != 0){
      cout << -1 << endl;
      return 0;
    }
  }

  cout << day << endl;

  return 0;
}