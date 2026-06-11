#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n;
  cin >> n;
  map<int, int> a;
  rep(i, n - 1) {
    int s;
    cin >> s;
    a[s - 1]++;
  }
  rep(i, n) { cout << a[i] << endl; }
}
