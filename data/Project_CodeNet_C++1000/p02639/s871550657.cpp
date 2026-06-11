#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a[5];
    rep(i, 5) {
        cin >> a[i];
        if (a[i] == 0) cout << i + 1 << endl; 
    }
    return 0;
}