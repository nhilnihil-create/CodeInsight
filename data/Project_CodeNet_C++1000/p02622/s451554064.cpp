#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string S, T; cin >> S >> T;
    int n = S.size();
    int cnt = 0;
    rep(i, n) {
        if(S[i] != T[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}