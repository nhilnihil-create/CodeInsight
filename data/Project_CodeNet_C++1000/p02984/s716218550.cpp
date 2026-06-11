#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  vector<ll> X(N); // 答え
  ll sum = 0; // sum:=A[1]+A[3]+\cdots+A[N-2]
  for (int i=1; i<N; i+=2) sum += A[i];
  X[0] = accumulate(A.begin(), A.end(), 0LL)-2*sum;
  // 漸化式
  for (int i=1; i<N; i++) X[i] = 2*A[i-1]-X[i-1];
  for (int i=0; i<N; i++) {
    if (i!=N-1) cout << X[i] << " ";
    else cout << X[i] << endl;
  }
}