#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[50]; // dp[i]: i段目まで上り方の種類

void init() {
   dp[1] = 1, dp[2] = 2, dp[3] = 4;
   for (int i = 4; i <= 30; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
   }
}

int main() {
   init();
   while (1) {
      int n;
      cin >> n;
      if (!n) break;
      ll day = max(1LL, dp[n] / 10);
      cout << day / 365 + (day%365 != 0) << endl;
   }

   return 0;
}
