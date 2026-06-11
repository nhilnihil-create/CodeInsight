#include <bits/stdc++.h>

using namespace std;

long long Solve(long long a, long long b, long long g) {
    return b / g - (a - 1) / g;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   long long a, b, c, d;
   cin >> a >> b >> c >> d;
   long long g = c / __gcd(c, d) * d;
   long long Not = Solve(a, b, c) + Solve(a, b, d) - Solve(a, b, g);
   long long ans = b - a + 1 - Not;
   cout << ans << endl;
}