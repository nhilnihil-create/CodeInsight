#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;


int main() {
  int N;
  cin >> N;
  vector<pair <ll, ll>> task;

  REP(n,N){
    ll a, b;
    cin >> a >> b;
    task.emplace_back(b,a);
  }

  sort(task.begin(), task.end());

  ll sum = 0;
  bool flag = true;

  for(auto v : task){
    sum += v.second;
    
    if (sum > v.first) {
      flag = false;
      break;
    }
  }

  if (flag == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

}
