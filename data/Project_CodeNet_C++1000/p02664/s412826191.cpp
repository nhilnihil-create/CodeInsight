#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
#define REP(i,n) for (int i = 1; i<= (n); i++)
#define MAX_MOD 1000000007LL
#define MOD 998244353LL
const long double PI = acos(-1);
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    string t;
    cin >> t;
    rep(i, t.size()) {
        if (t[i] == '?') {
            t[i] = 'D';
        }
    }
    cout << t << endl;
    return 0;
}