#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++)
  {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int K = d[N /2] - d[N / 2 - 1];
  cout << K << endl;
  
  return 0;
}
