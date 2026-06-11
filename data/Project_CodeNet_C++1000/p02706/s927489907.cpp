#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  int homework = 0;
  for (int i = 0;i < M; i++) {
    int tmp;
    cin >> tmp;
    homework += tmp;
  }
  if (homework > N) cout << -1 << endl;
  else cout << N - homework << endl;
}
