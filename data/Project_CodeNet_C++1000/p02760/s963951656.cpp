#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    map<ll, ll> A;
    REP(i, 9) {
        ll tmp;
        cin >> tmp;
        A[tmp] = i + 1;
    }

    ll N;
    cin >> N;

    bool isHit[9];
    REP(i, 9) {
        isHit[i] = false;
    }

    REP(i, N) {
        ll num;
        cin >> num;
        if(A[num] != 0) {
            isHit[A[num] - 1] = true;
        }
    }

    ll atari[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},

        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},

        {0, 4, 8},
        {2, 4, 6}
    };

    REP(i, 8) {
        bool tmp = true;
        REP(j, 3) {
           if(!isHit[atari[i][j]]) {
               tmp = false;
           }
        }

        if(tmp) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}