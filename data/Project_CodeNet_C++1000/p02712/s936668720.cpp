#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, sum = 0;
    cin >> n;
    rep(i, n) {
        if((i + 1) % 3 == 0) {
            continue;
        } else if((i + 1) % 5 == 0) {
            continue;
        } else {
            sum += i + 1;
        }
    }
    cout << sum << endl;
    return 0;
}