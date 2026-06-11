#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> d(n);
    rep(i,n) cin >> d[i];

    sort(d.begin(), d.end());

    if (d[d.size()/2] == d[d.size()/2-1]) {
        cout << 0 << endl;
    }
    else {
        cout << d[d.size()/2]-d[d.size()/2-1] << endl;
    }
    return 0;
}