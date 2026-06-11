#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<int> cnt(1001001);

void calc(int n) {
  for(ll i = 2; i*i <= n; i++) {
    if(n % i != 0) continue;
    while(n % i == 0) {
      n/= i;
    }
    cnt[i]++;
  }
  if(n != 1) cnt[n]++;
}

int main() {
  int n;
  cin >> n;
  rep(i,n) {
    int a;
    cin >> a;
    calc(a);
  }
  int mx = 0;
  rep(i,1001001) {
    mx = max(mx, cnt[i]);
  }
  if (mx >= n) cout << "not coprime" << endl;
  else if (mx <= 1) cout << "pairwise coprime" << endl;
  else cout << "setwise coprime" << endl;
  return 0;
}
