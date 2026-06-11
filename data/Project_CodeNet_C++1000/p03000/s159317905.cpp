#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    int n,x;
    cin >> n >> x;
    int a[n];
    rep(i,n) cin >> a[i];
    int d = 0, cnt = 1;
    rep(i,n) {
      if (d + a[i] > x) break;
      cnt++;
      d += a[i]; 
    }
    cout << cnt << endl;
    return 0;
}