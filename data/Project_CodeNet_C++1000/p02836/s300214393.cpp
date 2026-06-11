#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    string S;
    cin >> S;
    int N = S.length(), ans = 0;
    rep(i,N/2) {
        ans += S[i] != S[N-1-i];
    }
    cout << ans << endl;
    return 0;
}
