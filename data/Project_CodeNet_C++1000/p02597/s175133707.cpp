#include <bits/stdc++.h>
using namespace std;
// types
typedef long long ll; 
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
// IO
#define fo(i, n) for (int i = 0; i < n; i++)
#define fo1(i, n) for (int i = 1; i <= n; i++)
#define sc(n) scanf("%d", &n) 
#define sca(a, n) fo(i, n) sc(a[i])
#define pd(a) printf("%d ", a)
#define pld(a) printf("%d\n", a)
#define pda(a, n) fo(i, n) pd(a[i])
#define pl printf("\n")
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b) 
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
// math
const ll mod = 1e9+7;
template<typename T> T gcf(T a, T b) {return (b == 0) ? a : gcf(b, a%b);} 
template<typename T> T lcm(T a, T b) {return (a*b)/gcf(a, b);}
template<typename T> T sumTo(T x) {return x * (x+1) / 2;}
template<typename T> T sumSquaresTo(T x) {return x * (x+1) * (2*x+1) / 6;}
template<typename T> T ceilDiv(T n, T d) {return (n+d-1)/d;}

int diff(int a, int b) {
    return max(a-b, b-a);
}

void solve() {
    int n; sc(n);
    string s; cin >> s;
    bool red[n+1]; fo1(i, n) red[i] = s[i-1] == 'R';
    int rp[n+1]; rp[0] = 0; 
    fo1(i, n) {
        rp[i] = rp[i-1];
        if (red[i]) rp[i]++;
    }
    int ans = 1e9;
    fo(nr, n+1) {
        int nswap = nr-rp[nr];
        int nrep = diff(nr, rp[n]);
        ans = min(ans, nswap+nrep);
    }
    cout << ans;
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}