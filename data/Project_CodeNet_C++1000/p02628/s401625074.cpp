#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  int count = 0;
  cin >> N >> K;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
  {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  for (int j = 0; j < K; j++)
  {
    count += vec.at(j);
  }
  cout << count << endl;
}