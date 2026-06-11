#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n, x[100], y[100];

int main(){
  cin >> n;
  rep(i, n) cin >> x[i] >> y[i];
  map<P, int> mp;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      mp[P(x[i] - x[j], y[i] - y[j])]++;
      mp[P(x[j] - x[i], y[j] - y[i])]++;
    }
  }
  int m = 0;
  for(auto x : mp){
    m = max(x.second, m);
  }
  cout << n - m << endl;
}
