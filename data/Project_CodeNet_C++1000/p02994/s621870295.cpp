#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, l;
    cin >> n >> l;
    int s = 0;
    int t = l;
    bool ok = false;
    rep(i,n) {
        if (t == 0) ok = true;
        s += t;
        t++;
    }
    if (ok) cout << s << endl;
    else if (l<0) cout << s-t+1 << endl;
    else cout << s-l << endl;
    return 0;
}
