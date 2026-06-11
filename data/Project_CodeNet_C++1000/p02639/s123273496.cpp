#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<int> a(5);
    rep(i,5) cin >> a[i];
    rep(i,5) {
        if (a[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}