#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {

    int n;
    cin >> n;

    vector<int> a(n),b(n);
    rep(i,n) {
        cin >> a[i];
        b[i] = a[i];
    }


    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j = n-1; j >= 0; j--) {
            if (f || a[i] != b[j]) {
                cout << b[j] << endl;
                break;
            }
            else if (!f) {
                f = true;
            }
        }
    }
        
    return 0;
}