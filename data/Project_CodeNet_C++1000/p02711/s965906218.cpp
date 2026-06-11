#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   if (n%10==7 || (n/10)%10==7 || (n/100)%10==7)
      cout << "Yes" << endl;
   else
      cout << "No" << endl; 
}