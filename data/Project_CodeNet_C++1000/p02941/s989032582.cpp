#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<ll> a(n+2);
    for (int i=1; i<=n; i++) {
        cin >> a.at(i);
    }
    a.at(0) = a.at(n);
    a.at(n+1) = a.at(1);
    vector<ll> b(n+2);
    for (int i=1; i<=n; i++) {
        cin >> b.at(i);
    }
    b.at(0) = b.at(n);
    b.at(n+1) = b.at(1);
    priority_queue<pair<ll, int>> que;
    for (int i=1; i<=n; i++) {
        if (a.at(i) != b.at(i)) {
            que.push(make_pair(b.at(i), i));
        }
    }
    ll cnt = 0;
    while (!que.empty()) {
        int i = que.top().second;
        que.pop();
        ll buf = b.at(i-1) + b.at(i+1);
        if (buf > b.at(i)) {
            cout << -1 << endl;
            return 0;
        }
        if (b.at(i)%buf > a.at(i)) {
            cnt += b.at(i)/buf;
            b.at(i) = b.at(i)%buf;
            if (i == 1) {
                b.at(n+1) = b.at(1);
            }
            else if (i == n) {
                b.at(0) = b.at(n);
            }
            que.push(make_pair(b.at(i), i));
        }
        else {
            if ((b.at(i)-a.at(i))%buf == 0) {
                cnt += (b.at(i)-a.at(i))/buf;
                b.at(i) = a.at(i);
                if (i == 1) {
                    b.at(n+1) = b.at(1);
                }
                else if (i == n) {
                    b.at(0) = b.at(n);
                }
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
