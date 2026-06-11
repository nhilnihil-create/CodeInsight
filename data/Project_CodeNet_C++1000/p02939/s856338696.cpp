#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     string S;
     cin >> S;
     set<string> s;
     int n = S.length();
     if (n == 1) cout << 1 << endl;
     if (n == 2) {
       if (S.at(0) == S.at(1)) cout << 1 << endl;
       else cout << 2 << endl;
     }

     else {
       vector<int> dp(n);
       dp.at(0) = 1;
       if (S.at(0) == S.at(1)) dp.at(1) = 1;
       else dp.at(1) = 2;
       if (S.at(0) != S.at(1) && S.at(1) != S.at(2)) dp.at(2) = 3; // aba -> a, b, a
       else dp.at(2) = 2;

       for (int i = 3; i < n; i++) {
         if (S.at(i - 1) == S.at(i)) dp.at(i) = dp.at(i - 3) + 2; // ??aa -> ?, ?a, a or ?, ?, aa
         else dp.at(i) = dp.at(i - 1) + 1; // ?ab -> ?, a, b or ?a, b
       }
       cout << dp.at(n - 1) << endl;
     }
 }
