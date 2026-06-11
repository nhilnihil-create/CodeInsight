#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) {
    cin >> vec.at(i);
  }
  int minCost = 100000000;
  for (int i = 1; i < 101; i++) {
    int cost = 0;
    for (int j : vec) {
      cost += pow((i - j),2);
    }
    minCost = min(minCost, cost);
  }
  cout << minCost << endl;
}
