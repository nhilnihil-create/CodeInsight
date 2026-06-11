#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    --A;
    --B;
    --C;
    --D;

    for (int i = A; i < C; ++i) {
        if (S.at(i) == '#' && S.at(i+1) == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = B; i < D; ++i) {
        if (S.at(i) == '#' && S.at(i+1) == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    if (C < D) cout << "Yes" << endl;
    else {
        rep(i,N-2) {
            if (S.at(i) == '.' && S.at(i+1) == '.' && S.at(i+2) == '.' 
            && B <= i + 1 && i + 1 <= D) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
}

