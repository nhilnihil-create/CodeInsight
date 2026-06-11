#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    ll sm = 0;
    map<int, int> m;
    for (int& e : a) {
        cin >> e;
        sm += m[e];
        m[e]++;
    }

    for (int i=0; i<n; i++) {
        cout << sm - m[a[i]]+1 << "\n";
    }
}
