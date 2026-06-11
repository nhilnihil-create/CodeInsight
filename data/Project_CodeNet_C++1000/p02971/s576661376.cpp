#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N;
    cin >> N;

    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll max = 0, prev_max = 0;
    REP(i, N) {
        if(A[i] > max) {
            prev_max = max;
            max = A[i];
        } else {
            if(A[i] > prev_max) {
                prev_max = A[i];
            }
        }
    }

    REP(i, N) {
        if(A[i] != max) {
            cout << max << endl;
        } else {
            cout << prev_max << endl;
        }
    }

    return 0;
}