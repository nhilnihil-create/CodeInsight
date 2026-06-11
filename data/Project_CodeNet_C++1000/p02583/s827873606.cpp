#include <iostream>
#include <string>
#include <algorithm>
#define ill long long
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<ill> v(n);
  rep(i,0,n) cin >> v[i];
  sort(v.begin(), v.end());
  ill sum = 0;
  rep(i, 0, n) {
    rep(j, i, n) {
      rep(k, j, n) {
        if(v[i] != v[j] && v[j] != v[k] && v[i] + v[j] > v[k]) sum++;
      }
    }
  }
  cout << sum << "\n";
}