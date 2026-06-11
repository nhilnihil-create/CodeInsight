#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
double x, y;
priority_queue<double> pq;
int n;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        pq.emplace(-x);
    }
    while (pq.size() > 1) {
        x = -pq.top();
        pq.pop();
        y = -pq.top();
        pq.pop();
        pq.emplace(-(x + y) / 2.0);
    }
    x = -pq.top();
    pq.pop();
    cout << fixed << setprecision(10) << x;
    PLEC
}
