#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int k, x;
   cin >> k >> x;

   string ans = (500 * k >= x) ? "Yes" : "No";

   cout << ans << endl;
}