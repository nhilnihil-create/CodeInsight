#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,x,t;
    cin >> n >> x >> t;
    if (n <= x) {
        cout << t << endl;
    } else {
        if (n%x == 0) {
            cout << (n/x) * t << endl;
        } else {
            cout << ((n/x)+1) * t << endl;
        }
    }
    return 0;
}