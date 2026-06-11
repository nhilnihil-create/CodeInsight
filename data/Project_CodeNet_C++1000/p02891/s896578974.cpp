#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    set<char> st(S.begin(), S.end());
    if (st.size() == 1) {
        cout << S.size() * K / 2 << '\n';
        return 0;
    }
    ll cnt1 = 0;
    char cur = S[0];
    for (int i = 0; i < S.size() - 1; i++) {
        if (cur == S[i+1]) {
            cnt1++;
            i++;
        }
        cur = S[i+1];
    }
    ll ans = K * cnt1;
    //cout << ans << '\n';
    if (*S.begin() == *S.rbegin()) {
        int a = 1, b = 1;
        for (int i = 0; S[i] == S[i+1]; i++, a++) {;}
        for (int i = S.size() - 1; S[i] == S[i-1]; i--, b++) {;}
        //cout << a << b << '\n';
        ans += -(K - 1) * (a/2 + b/2) + (K - 1) * ((a + b) / 2);
    }
    cout << ans << '\n';
}
