#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int a, b;
    cin >> a >> b;
    repi(i, 2001) {
        if (i * 8 / 100 == a && i * 10 / 100 == b) {
            put(i);
            return 0;
        }
    }

    put(-1)
    
    return 0;
}