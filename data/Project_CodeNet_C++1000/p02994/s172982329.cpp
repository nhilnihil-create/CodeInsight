#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  long long S = 0;
  for (long long i = 0; i < N; ++i) {
    S += L + i;
  }
  long long R = L + N - 1; 
  if (L >= 0) cout << S - L << endl;
  else if (R <= 0) cout << S - R << endl;
  else cout << S << endl;
}