#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG


int main() {
  ll N, K;
  cin >> N >> K;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  
  double ans_f = log(N)/log(K);

  cout << (int)ans_f + 1 << endl;

  return 0;
}
