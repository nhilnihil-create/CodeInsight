#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int K, X;
    cin >> K >> X;

    int minV = X - K + 1;
    int maxV = X + K - 1;

    for (int i = minV; i <= maxV; i++) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
