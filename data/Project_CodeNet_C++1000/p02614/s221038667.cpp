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

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    
    int nPatW = 1;
    int nPatH = 1;
    rep(i,h) nPatH *= 2;
    rep(i,w) nPatW *= 2;

    int ans = 0;
    rep(py, nPatH) {
        rep(px, nPatW) {
            vector<string> t = c;
            rep(i, h) {
                if (py & (1 << i)) {
                    rep(z, w) t[i][z] = 'r'; 
                }
            }
            rep(j, w) {
                if (px & (1 << j)) {
                    rep(z, h) t[z][j] = 'r'; 
                }
            }
            int cnt = 0;
            rep(y, h) rep(x, w) if (t[y][x] == '#') cnt++;
            if (cnt == k) ans++;
        }
    }

    put(ans);
    
    return 0;
}