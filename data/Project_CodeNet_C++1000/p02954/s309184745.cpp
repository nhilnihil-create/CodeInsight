#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string S;
    cin >> S;

    int n = S.size();
    vector<int> L(n), R(n);
    L[0] = S[0] == 'L' ? 1 : 0;
    R[0] = S[0] == 'R' ? 1 : 0;
    repi(i, n) {
        L[i] = L[i-1] + (S[i] == 'L' ? 1 : 0);
        R[i] = R[i-1] + (S[i] == 'R' ? 1 : 0);
    }

    vector<int> pos(n);
    rep(i, n) {
        if (S[i] == 'L') {
            int r = lower_bound(R.begin(), R.begin() + i, R[i]) - R.begin();
            int p = (i - r) % 2 == 1 ? r + 1 : r;
            pos[p]++;
        }
        else {
            int l = upper_bound(L.begin() + i, L.end(), L[i]) - L.begin();
            int p = (l - i) % 2 == 1 ? l - 1 : l;
            pos[p]++;
        }
    }

    rep(i, pos.size()) cout << pos[i] << (i == pos.size() - 1 ? "" : " ");
    cout << endl;

}
signed main(){ Main();return 0;}