#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m1 = 0, i1 = 0;
    rep(i,n) {
        cin >> a[i];
        if (max(m1,a[i]) != m1) {
            i1 = i;
            m1 = a[i];
        }
    }
    a[i1] = 0;
    int m2 = 0;
    rep(i,n) {
        m2 = max(m2,a[i]);
    }
    rep(i,n) {
        if (i == i1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}

