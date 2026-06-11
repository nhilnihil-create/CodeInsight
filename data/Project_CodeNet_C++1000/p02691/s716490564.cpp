#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> m;
  long long ans = 0;
  for(int i = 0; i < N; i++) cin >> A[i];
  //*
  for(int i = 1; i < N; i++){  
    int x = (A[0] + A[i]) - i;
    m[x]++;
  }
  int a = 0;
  ans += m[0];
  for(int i = 1; i < N; i++){  
    int x = (A[0] + A[i]) - i;
    m[x]--;
    a = -1 * ((A[i] - A[0]) + i);
    ans += m[a];
  }
  cout << ans <<endl;
  //*/
}
