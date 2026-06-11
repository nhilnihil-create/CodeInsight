#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll N, M;
  cin >> N >> M;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));


  
  cout << (N-1)*N/2 + (M-1)*M/2 << endl;

  return 0;
}
