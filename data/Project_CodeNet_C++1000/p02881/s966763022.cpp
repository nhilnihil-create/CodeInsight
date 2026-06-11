#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll n;
    cin >> n;
    if(floor(sqrt(n)) * float(sqrt(n)) == n) { //nが平方数の場合
        cout << (ll)(sqrt(n) * 2 - 2) << endl;
        return 0;
    }
    for(int i = floor(sqrt(n)); i >= 1; i--) { //nが平方数でないときはしらみつぶし(10^6程度で終わるはず)
        if(i * (n / i) == n) {
            cout << (i - 1) + ((n / i) - 1) << endl;
            return 0;
        }
        continue;
    }
}
