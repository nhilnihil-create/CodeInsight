#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int codei[4] = {1, 1, -1, -1};
const int codej[4] = {-1, 1, -1, 1};

int main() {
    ll X;
    cin >> X;
    vector<ll> num(10001);
    for (ll i = 0; i < 10001; ++i) {
        num.at(i) = i;
        rep(j,4) num.at(i) *= i;
    }
    rep(i,10001) for (int j = i + 1; j < 10001; ++j) {
        rep(k,4) if (num.at(i) * codei[k] - num.at(j) * codej[k] == X) {
            cout << i * codei[k] << " " << j * codej[k] << endl;
            return 0;
        }
    }
}
