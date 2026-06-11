#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100010]; 
int main() {
  string s; cin >> s;
  int n = s.size();
  rep(i,n) {
    int st = i;
    while (i<n-1 && s[i] == s[i+1]) i++;
    int suc = i-st+1;
    if (s[i] == 'L') {
      a[st] += (suc+1) / 2;
      a[st-1] += suc / 2;
    } else {
      a[i] += (suc+1) / 2;
      a[i+1] += suc / 2;
    }
  }
  rep(i,n) cout << a[i] << " ";
  cout << endl;
  return 0;
}