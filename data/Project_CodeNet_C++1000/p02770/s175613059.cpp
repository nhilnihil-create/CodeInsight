#include <bits/stdc++.h>
using namespace std;

#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n-1);i>=0;i--)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define D(a) cerr << #a << " = " << a << endl
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
typedef pair<int,int> pii;
typedef long long int ll;
typedef vector<int> vi;
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int k, q; cin >> k >> q;
    vi d(k), e(k);
    forn(i, k) cin >> d[i];

    while (q--) {
        int n, x, m; cin >> n >> x >> m, n--;
        ll s = 0, z = 0;
        forn(i, k) {
            e[i] = d[i] % m;
            s += e[i];
            if (e[i] == 0) z++;
        }
        ll y = x % m + n/k * s;
        int l = n % k;
        z *= n/k; 
        forn(i, l) {
            y += e[i];
            if (e[i] == 0) z++;
        }
        cout << n - z - y/m << endl;
    }
    return 0;
}
