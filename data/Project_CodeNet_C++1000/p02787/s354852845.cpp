#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int INF = 1e9 + 5;

ll pot(ll base, ll potencia) {
    ll tot = 1;
    for (int i = 0; i <= potencia - 1; i++) {
        //cout << tot << '\n';
        tot *= base;
    }
    return tot;
}

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> dp(h + 1, INF);
    dp[0] = 0;
    //printVector(dp);
    while (n--) {
        int valor, custo;
        cin >> valor >> custo;
        for (int i = 0; i <= h; i++) {
            int j = min(h, i + valor);
            dp[j] = min(dp[j], dp[i] + custo);
        }
    }
    cout << dp[h] << '\n';
    return 0;
}