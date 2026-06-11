#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int x,rem;
    int f=0, o=0;
    cin >> x;
    if (x < 100)cout << 0 << endl;
    else {
        rem = x / 100;
        x %= 100;
        if (x >= 5) {
            f = x / 5;
            x %= 5;
        }
        if (x >= 1)o = 1;
        if (rem >= (f + o))cout << 1 << endl;
        else cout << 0 << endl;

    }
    return 0;

}
