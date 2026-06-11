#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int x[N], l[N];
pair<int, int> ps[N];

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> l[i];
    }
    for (int i = 0; i < n; i++) {
        ps[i] = make_pair(x[i] + l[i], x[i] - l[i]);
    }
    sort(ps, ps + n);
    int cur = INT_MIN, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur <= ps[i].second) {
            ++cnt;
            cur = ps[i].first;
        }
    }
    cout << cnt << '\n';
}