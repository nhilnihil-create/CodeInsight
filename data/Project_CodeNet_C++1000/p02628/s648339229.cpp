#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N, K;
  cin >> N >> K;
  vector<int> juice(N);
  for(int i = 0; i < N; i++) cin >> juice[i];
  sort(juice.begin(), juice.end());
  int ans = 0;
  for(int i = 0; i < K; i++){
    ans += juice[i];
  }
  cout << ans <<endl;
}