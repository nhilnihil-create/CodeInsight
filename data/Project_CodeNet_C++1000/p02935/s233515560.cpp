#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  double ans = v[0];
  for(int i = 0; i < N - 1; ++i) {
    ans = (v[i + 1] + ans) / 2;
  }

  cout << ans << endl;

  return 0;
}
