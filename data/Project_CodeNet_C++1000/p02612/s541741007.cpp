#include <bits/stdc++.h>
using namespace std;

int N;
void input() { cin >> N; }
void solve() { cout << ((N % 1000 != 0) ? (1000 - N % 1000) : 0) << endl; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}