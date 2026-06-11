#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m; cin >> n >> m;
   rep(i,m){
      if (n%2==0 && (i+1)*2-1==n/2)n--;
      cout << i+1 << " " << n-i << endl;
      if (n%2==0 && (i+1)*2==n/2)n--;
   }
}