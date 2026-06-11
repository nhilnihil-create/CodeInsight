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
    int n, m;
    cin >> n >> m;

    vector<int> s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];
    

    int H = 1, L = 1;
    rep(i, n-1) L *= 10;
    H = L * 10;
    if (L == 1) L = 0;
    for (int i = L; i < H; i++){
        bool ok = true;

        string str = to_string(i);
        if (str.size() != n) {
            continue;
        } 

        rep(j, m){
            if (str[s[j] - 1] != '0' + c[j]) {
                ok =false;
                break;
            }
        }
        
        if (ok) {
            put(i);
            return 0;
        }
    }

    put(-1);
    
    return 0;
}