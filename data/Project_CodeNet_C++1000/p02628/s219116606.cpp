#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  int N, K, input;
  cin >> N >> K;
  vector<int> prices;
  for (int i = 0; i < N; ++i) {
  	cin >> input;
    prices.push_back(input);
  }
  sort(prices.begin(), prices.end());
  int cost = 0;
  for (int i = 0; i < K; ++i)
    cost += prices[i];
  cout << cost << '\n';
  return 0;
}