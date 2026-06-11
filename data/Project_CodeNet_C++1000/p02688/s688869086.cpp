#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x;
        for (int j=0; j<x; j++) {
            cin >> y;
            a[y-1]++;
        }
    }

    int cnt = 0;
    for (int e : a) cnt += e == 0;
    cout << cnt << "\n";
}
