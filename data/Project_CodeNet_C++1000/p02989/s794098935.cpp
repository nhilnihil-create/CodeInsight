#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  int D[N]; for (int &d: D) cin >> d; sort(D, D + N);
  cout << D[N / 2] - D[N / 2 - 1];}