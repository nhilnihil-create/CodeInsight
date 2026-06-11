#include <bits/stdc++.h>
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
void Main()
{
    string S;
    cin >> S;

    deque<char> T;
    rep(i, S.size()) T.push_back(S[i]);

    ll Q;
    cin >> Q;

    bool flip = false;
    rep (i, Q) {
        int flg;
        cin >> flg;
        if (flg == 1) {
            flip = !flip;
        }
        else if (flg == 2) {
            int f;
            char c;
            cin >> f >> c;
            if (flip) f = 3 - f;
            if (f == 1) {
                T.push_front(c);
            }
            else {
                T.push_back(c);
            }
        }
    }

    if (flip) reverse(all(T));

    rep(i, T.size()) cout << T[i];
    cout << endl;

}
signed main(){ Main();return 0;}