#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int T1, T2;
    cin >> T1 >> T2;

    ll A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;

    ll A = (A1 - B1) * T1, B = (A2 - B2) * T2;

    if (A < 0) {
        A = -A;
        B = -B;
    }

    if (A + B > 0) {
        puts("0");
        return 0;
    } else if (A + B == 0) {
        cout << "infinity" << endl;
        return 0;
    }

    ll ans = (-A / (A+B)) * 2 + 1;
    if (-A % (A+B) == 0) {
        ans -=1;
    }

    cout << ans << endl;
}