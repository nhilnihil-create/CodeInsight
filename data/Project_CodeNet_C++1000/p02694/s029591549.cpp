#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll x; cin >> x;
   ll money = 100;
   ll year = 0;
   while (money < x){
      year++;
      money += money/100;
   }
   cout << year << endl;
}