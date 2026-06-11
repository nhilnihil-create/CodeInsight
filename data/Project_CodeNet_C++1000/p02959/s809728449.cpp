#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n);
    for (int i = 0; i < n + 1; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }
    ll cnt = 0;
    for (int i = 0; i < n + 1 / 2; i++) {
        //最初
        if (a.at(i) < b.at(i)) {
            cnt += a.at(i);
            b.at(i) -= a.at(i);
            a.at(i) = 0;
            if (a.at(i + 1) > b.at(i)) {
                cnt += b.at(i);
                a.at(i + 1) -= b.at(i);
                b.at(i) = 0;
            } else {
                cnt += a.at(i + 1);
                b.at(i) -= a.at(i + 1);
                a.at(i + 1) = 0;
            }
        } else {
            cnt += b.at(i);
            a.at(i) -= b.at(i);
            b.at(i) = 0;
        }

        //最後
        if (a.at(n - i) < b.at(n - i - 1)) {
            cnt += a.at(n - i);
            b.at(n - i - 1) -= a.at(n - i);
            a.at(n - i) = 0;
            if (a.at(n - i - 1) > b.at(n - i - 1)) {
                cnt += b.at(n - i - 1);
                a.at(n - i - 1) -= b.at(n - i - 1);
                b.at(n - i - 1) = 0;
            } else {
                cnt += a.at(n - i - 1);
                b.at(n - i - 1) -= a.at(n - i - 1);
                a.at(n - i - 1) = 0;
            }
        } else {
            cnt += b.at(n - i - 1);
            a.at(n - i) -= b.at(n - i - 1);
            b.at(n - i - 1) = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}