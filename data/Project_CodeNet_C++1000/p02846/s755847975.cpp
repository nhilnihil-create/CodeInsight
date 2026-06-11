#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    ll T[2];
    cin >> T[0] >> T[1];
    ll A[2], B[2];
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    if(A[0] > B[0] && A[1] > B[1]) {
        cout << 0 << endl;
    } else if(A[0] < B[0] && A[1] < B[1]) {
        cout << 0 << endl;
    }else if(A[0]>B[0] && (A[0]-B[0])*T[0] + (A[1]-B[1])*T[1] >0){
        cout << 0 << endl;
    } else if(A[0] < B[0] && (-A[0] + B[0]) * T[0] + (-A[1] + B[1]) * T[1] > 0) {
        cout << 0 << endl;
    } else {
        ll x = A[0] * T[0] + A[1] * T[1];
        ll y = B[0] * T[0] + B[1] * T[1];
        ll dd = abs(x - y);
        if(dd == 0) {
            cout << "infinity" << endl;
            return 0;
        }

        ll ddx = abs(A[0] - B[0]) * T[0];
        ll cnt = (ddx+dd-1) / dd;
        cout << cnt * 2 - 1 + (ddx%dd==0) << endl;
    }
    return 0;
}