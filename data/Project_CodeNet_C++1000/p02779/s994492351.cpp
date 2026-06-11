#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
    int n;
    cin >> n;
    vec(int) a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        if (a[i] == a[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}