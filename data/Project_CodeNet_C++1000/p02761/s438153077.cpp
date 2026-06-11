#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> s(M);
  vector<char> c(M);
  rep(i,M) cin >> s[i] >> c[i];
  vector<char> number(N);
  rep(i,N) number[i] = 'A';
  rep(i,M) {
    if (number[s[i]-1] == 'A') number[s[i]-1] = c[i];
    else if (number[s[i]-1] != c[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (number.size() != 1 && number[0] == '0') {
    cout << -1 << endl;
    return 0;
  };
  rep(i,N) {
    if (number[i] == 'A') number[i] = '0';
  }
  if (number.size() != 1 && number[0] == '0') number[0] = '1';


  rep(i,N) cout << number[i];
  cout << endl;
  return 0;
}