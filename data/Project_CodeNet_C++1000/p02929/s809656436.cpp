#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const long long INF = 2e18;
const long long MOD = 1e9+7;

#define sx(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a),end(a)

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (S[0] == 'W' || S[2*N-1] == 'W') {
        cout << 0 << endl;
        return 0;
    }

    string d;

    d.pb('l');
    for (int i=1; i<2*N; i++) {
        if (S[i] == 'B') {
            if (i % 2 == 0) {
                d.pb('l');
            }
            else {
                d.pb('r');
            }
        }
        else {
            if (i % 2 == 0) {
                d.pb('r');
            }
            else {
                d.pb('l');
            }
        }
    }
    /* 
    if (d[2*N-1] == 'l') {
        cout << 0 << endl;
        return 0;
    }
    */
    ll ans = 1;
    ll lef = 0, rig = 0;
    
    REP(i,2*N) {
        if (d[i] == 'l') {
            lef++;
        }
        else {
            ans *= lef;
            ans %= MOD;
            lef--;
        }
    }
    ans %= MOD;

    if (rig != lef) {
        cout << 0 << endl;
        return 0;
    }

    REP(i,N) {
        ans *= (i+1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;   
}