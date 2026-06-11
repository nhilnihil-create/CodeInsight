#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    vector<vector<ll>> A(3, vector<ll>(3, 0));
    rep(i,3) {
        rep(j,3) {
            ll tmp; cin >> tmp;
            A[i][j] = tmp;
        }
    }
    ll N; cin >> N;
    rep(k, N) {
        ll tmp; cin >> tmp;
        rep(i,3) {
        rep(j,3) {
            if (A[i][j] == tmp) {
                A[i][j] = -1;
            }
        }
        }
    }
    rep(i,3) {
        if (A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    rep(i,3) {
        if (A[0][i] == -1 && A[1][i] == -1 && A[2][i] == -1) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    if (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) {
        cout << "Yes" << endl;
        exit(0);
    }
    if (A[0][2] == -1 && A[1][1] == -1 && A[2][0] == -1) {
        cout << "Yes" << endl;
        exit(0);
    }
    cout << "No" << endl;
}
