#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> L;

void calc(int d, string v) {
  if (v.size() == d) {
    L.push_back(stoll(v));
    return;
  }

  if (v.size() == 0) {
    rep(i, 9) calc(d, to_string(i + 1));
  } else {
    int now = v.at(v.size() - 1) - '0';
    if (now > 0) calc(d, v + to_string(now - 1));
    calc(d, v + to_string(now));
    if (now < 9) calc(d, v + to_string(now + 1));
  }
}

int main() {
  int K;
  cin >> K;
  rep(i, 10) calc(i + 1, "");
  cout << L.at(K - 1) << endl;
}
