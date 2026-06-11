#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll P = (A1 - B1) * T1;
    ll Q = (A2 - B2) * T2;
    if (P > 0) {
        P *= -1;
        Q *= -1;
    }
    if (P + Q < 0) {
        cout << 0 << endl;
    }
    else if (P + Q == 0) {
        cout << "infinity" << endl;
    }
    else {
        ll S = -P / (P + Q);
        ll T = -P % (P + Q);
        if (T != 0) cout << S * 2 + 1 << endl;
        else cout << S * 2 << endl;
    }
    return 0;
}