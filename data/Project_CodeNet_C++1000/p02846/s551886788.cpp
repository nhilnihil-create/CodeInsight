#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

int main() {
    ll T1,T2;
    cin >> T1 >> T2;
    ll A1,A2;
    cin >> A1 >> A2;
    ll B1,B2;
    cin >> B1 >> B2;
    if(T1 * A1 + T2 * A2 == T1 * B1 + T2 * B2) {
        cout << "infinity" << endl;
    }
    else {
        if(A1 > B1) {
            if(T1 * A1 + T2 * A2 > T1 * B1 + T2 * B2) {
                cout << 0 << endl;
            }
            else {
                ll cnt1 = (A1 - B1) * T1;
                ll cnt2 = cnt1 - (T1 * A1 * 2 + T2 * A2 - T1 * B1 * 2 - T2 * B2);
                if(cnt1 % cnt2 == 0) {
                    cout << 1 + (cnt1 / cnt2 - 1) * 2 + 1 << endl;
                }
                else {
                    cout << 1 + cnt1 / cnt2 * 2 << endl;
                }
            }
        }
        else {
            if(T1 * A1 + T2 * A2 < T1 * B1 + T2 * B2) {
                cout << 0 << endl;
            }
            else {
                ll cnt1 = (B1 - A1) * T1;
                ll cnt2 = cnt1 - (T1 * B1 * 2 + T2 * B2 - T1 * A1 * 2 - T2 * A2);
                if(cnt1 % cnt2 == 0) {
                    cout << 1 + (cnt1 / cnt2 - 1) * 2 + 1 << endl;
                }
                else {
                    cout << 1 + cnt1 / cnt2 * 2 << endl;
                }
            }
        }
    }
}
