#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll count(string &S) {
    ll x = 0;
    int even = 1;
    rep(i,S.size()-1) {
        if (S.at(i) == S.at(i + 1)) {
            if (even == 1) ++x;
            even *= -1;
        } else {
            even = 1;
        }
    }
    return x;
}

int main() {
    string S;
    ll K;
    cin >> S >> K;
    string S2 = S + S; 
    ll ans;
    if (S.size() == 1) {
        ans = K / 2;
    } else {
        bool same = true;
        rep(i,S.size()) {
            if (S.at(i) != S.at(0)) {
                same = false;
                break;
            }
        }
        if (same == true) {
            ans = S.size() * K / 2;
        } else {
            ans = count(S) + (K - 1) * (count(S2) - count(S));
        }
    }
    cout << ans << endl;
}
