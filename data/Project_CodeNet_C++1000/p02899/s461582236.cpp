#include <bits/stdc++.h>
using namespace std;

string join(const vector<int>& v, const char* delim = 0) {
  string s = to_string(v[0]);
  for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
    if (delim) s += delim;
    s += to_string(v[i]);
  }
  return s;
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  vector<int> rep(N);

  for (int i = 0; i < N; i++) {
    rep.at(vec.at(i) - 1) = i + 1;
  }

  cout << join(rep, " ") << endl;
}