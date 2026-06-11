#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<ll, ll>> job;
  ll a, b;
  REP(i, N) {
    cin >> a >> b;
    job.push_back(make_pair(b, a));
  }
  sort(job.begin(), job.end());

  ll current = 0ll;
  REP(i, N) {
    current += job.at(i).second;

    if (current > job.at(i).first) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
