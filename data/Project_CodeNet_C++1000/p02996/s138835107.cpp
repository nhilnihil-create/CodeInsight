#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<P> ab(n);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    ab[i] = P(b, a);
  }
  sort(ab.begin(), ab.end());
  int count = 0;
  bool flag = true;
  rep(i, n){
    count += ab[i].second;
    if (ab[i].first < count){
      flag = false;
      break;
    }
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}