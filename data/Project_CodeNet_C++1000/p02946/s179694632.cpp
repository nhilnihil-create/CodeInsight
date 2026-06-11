#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int k, x; cin >> k >> x;
   for (int i = x-k+1; i < k+x; i++){
      cout << i << " ";
   }
   cout << endl;
}