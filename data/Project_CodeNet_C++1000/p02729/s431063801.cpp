#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)


int main() {
    int n,m; cin >> n >> m;
  	int ans = 0;
  	ans += (n*(n-1))/2;
  	ans += (m*(m-1))/2;
  	cout << ans << endl;
}