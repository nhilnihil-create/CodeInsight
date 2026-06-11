#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) ((a)<<(b))
#define Rshift(a,b) ((a)>>(b))
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define sz(a) int(a.size())
#define mset(x) memset(x, 0, sizeof(x))
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int i;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans(0);
    int maxn(0);
    rep(i, n) maxn = max(a[i], maxn);
    vector<int> used(maxn+1, 0);
    xrep(i, 1, n) if (a[i] == a[i-1]) {
        int in = a[i];
        used[a[i]] = 1;
        while (in <= maxn) {
            used[in] = 1;
            in += a[i];
        }
    }
    rep(i, n) {
        int in = a[i];
        if (!used[in]) {
            ans++;
            while (in <= maxn) {
                used[in] = 1;
                in += a[i];
            }
        }
    }
    cout << ans << endl;
}
