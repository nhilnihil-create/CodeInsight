#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    ll X;
    cin >> X;

    ll balance = 100;
    ll years = 0;
    while (balance < X) {
        years++;
        balance += balance / 100;
    }

    cout << years << endl;

    return 0;
}
