#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    string s;
    cin >>s;
    bool ok = true;
    rep(i, s.size()) {
        if (i % 2 == 0) {
            if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D') {

            }
            else {
             //   println(i)
             //   println(s[i]);
                ok = false;
                break;
            }
        }
        else {
            if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D') {

            }
            else {
             //   println(i)
             //   println(s[i]);
                ok = false;
                break;
            }
        }
    }
    yorn(ok)
    return 0;
}