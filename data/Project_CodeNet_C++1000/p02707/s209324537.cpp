#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll N;
using pint = pair<ll, ll>;
vector<pint> mem;
vector<ll> A;

int main() {
  cin >>N;
  mem.resize(N);
  A.resize(N - 1);
  for (int i = 0; i < N - 1; i++) cin >> A[i];
  for (int i = 0; i<N-1; i++){
    mem[A[i] - 1].second++;
  }
  for (int i = 0; i < N; i++) cout << mem[i].second << endl;
  return 0;
}