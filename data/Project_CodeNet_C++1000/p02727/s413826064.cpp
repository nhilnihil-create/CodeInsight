#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans;
int X, Y, A, B, C, curP = 0, curQ = 0, curR = 0;
vi P, Q, R, S;

void solve(){
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    reverse(P.begin(), P.end());
    reverse(Q.begin(), Q.end());

    rep(i, X) S.push_back(P[i]);
    rep(i, Y) S.push_back(Q[i]);
    rep(i, C) S.push_back(R[i]);

    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());

    rep(i, X+Y) ans += S[i];

    cout << ans << endl;
}

int main(){
    cin >> X >> Y >> A >> B >> C;
    P.resize(A);
    Q.resize(B);
    R.resize(C);

    rep(i, A) cin >> P[i];
    rep(i, B) cin >> Q[i];
    rep(i, C) cin >> R[i];

    solve();
}
