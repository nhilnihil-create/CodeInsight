#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, n) {
    rep(j, d) {
      cin >> x.at(i).at(j);
    }
  }
  
  int cnt = 0;
  rep(i, n) {
    for(int j = i+1; j < n; j++) {
      int dist = 0;
      rep(k, d) {
        int diff = abs(x.at(i).at(k) - x.at(j).at(k));
        dist += diff * diff;
      }
      for(int k = 0; k <= dist; k++) {
        if(k * k == dist) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}

        
      