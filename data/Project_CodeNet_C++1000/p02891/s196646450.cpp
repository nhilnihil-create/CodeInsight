#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    string S;
    int K;
    cin >> S >> K;
    ll ans = 0;
    bool check = true;
    rep(i, S.size()-1) {
        if (S[i] != S[i+1]) {
            check = false;
            break;
        }
    }
    //全部同じ文字の場合
    if (check) {
        cout << S.size()*K/2 << endl;
        return 0;
    }
    char S1 = S[0];
    ll cnt1 = 1;
    rep2(i, 1, S.size()) {
        if (S[i] == S1) {
            cnt1++;
        }
        else {
            break;
        }
    }
    char S2 = S[S.size()-1];
    ll cnt2 = 1;
    for (int i = S.size()-2; i>=0; i--) {
        if (S[i] == S2) {
            cnt2++;
        }
        else {
            break;
        }
    }
    ll cnt = 0;
    ll res = 0;
    char next;
    rep(i, S.size()) {
        if (i == 0) {
            next = S[0];
            res += 1;
            continue;
        }
        if (S[i] == next) {
            res++;
        }
        else {
            cnt += res/2;
            next = S[i];
            res = 1;
        }
        if (i == S.size()-1) {
            cnt += res/2;
        }
    }
    if (S1 == S2) {
        cout << cnt*K - (cnt1/2 + cnt2/2 - (cnt1+cnt2)/2)*(K-1) << endl;
    }
    else {
        cout << cnt*K << endl;
    }
}