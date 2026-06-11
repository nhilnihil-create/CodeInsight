#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int total = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < m; i++) {
        if ( 4 * m * a[i] < total) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0; 
}

