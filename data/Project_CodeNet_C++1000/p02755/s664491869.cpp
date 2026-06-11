#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for  (int i=0; i<1e6; i++) {
        if ((int)(i*0.08) == a && (int)(i*0.1) == b) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
