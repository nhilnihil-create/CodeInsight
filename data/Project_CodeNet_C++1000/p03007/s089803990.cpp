#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N), p, m;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) >= 0) p.push_back(A.at(i));
    else m.push_back(A.at(i));
  }
  sort(p.begin(), p.end(), greater<int>());
  sort(m.begin(), m.end());
  if (m.empty()) {
    m.push_back(p.back());
    p.pop_back();
  }
  if (p.empty()) {
    p.push_back(m.back());
    m.pop_back();
  }
  vector<pair<int, int>> ope;
  int M = m.at(0);
  for (int i = 0; i+1 < p.size(); i++) {
    ope.push_back(make_pair(M, p.at(i)));
    M -= p.at(i);
  }
  ope.push_back(make_pair(p.back(), M));
  M = p.back() - M;
  for (int i = 1; i < m.size(); i++) {
    ope.push_back(make_pair(M, m.at(i)));
    M -= m.at(i);
  }
  cout << M << endl;
  for (auto p : ope) cout << p.first << " " << p.second << endl;
}