#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll a,b;
cin >> a >> b;
if ((a + b) % 2 != 0) cout << "IMPOSSIBLE" << endl;
else
    cout << (a + b) / 2 << endl;
}
