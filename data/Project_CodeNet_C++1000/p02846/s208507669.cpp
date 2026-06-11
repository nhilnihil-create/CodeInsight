#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll T1, T2;
    cin >> T1 >> T2;
    ll A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    if((A1 > B1 && A2 > B2) || (A1 < B1 && A2 < B2)) {
        cout << 0 << endl;
    } else {
        if(A1 < B1) {
            swap(A1, B1);
            swap(A2, B2);
        }
        // A1>B1
        ll C = A1 - B1;
        ll D = A2 - B2;
        if(C * T1 + D * T2 > 0) {
            cout << 0 << endl;
        } else if(C * T1 + D * T2 == 0) {
            cout << "infinity" << endl;
        } else {
            cout << (C * T1 / ((abs(D) * T2) - C * T1)) * 2 + 1 -
                        !(C * T1 % ((abs(D) * T2) - C * T1))
                 << endl;
        }
    }
    return 0;
}