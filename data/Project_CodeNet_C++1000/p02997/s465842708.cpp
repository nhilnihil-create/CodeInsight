#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    int m = (n-1) * (n-2) / 2 - k;
    if (m < 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << n-1+m << endl;
    for (int i = 1; i < n; ++i) {
        cout << 1 << " " << i+1 << endl;
    }
    int s = 0;
    for (int i = 1; i < n; ++i) {
        if (s >= m) break;
        for (int j = i+1; j < n; ++j) {
            if (s >= m) break;
            cout << i+1 << " " << j+1 << endl;
            s++;
        }
    }
    return 0;
}