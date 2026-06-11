#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int K, X;
  cin >> K >> X;
  vector<int> stone(1, X);
  for (int i = 1; i < K; i++) {
    stone.push_back(X-i);
    stone.push_back(X+i);
  }
  sort(stone.begin(), stone.end());
  for (int i = 0; i < stone.size(); i++) cout << stone[i] << " ";
}
