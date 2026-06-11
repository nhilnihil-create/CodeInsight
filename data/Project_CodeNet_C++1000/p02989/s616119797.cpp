#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int index(vector<int> d, int x) {
    rep(i, d.size()) {
        if(d[i] >= x)
            return i;
    }
    return -1;
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> d(n);
    int halfn = n / 2;

    rep(i, n) cin >> d[i];

    ::sort(d.begin(), d.end());

    cout << d[halfn] - d[halfn-1] << endl;
}