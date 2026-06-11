#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int l[200010], r[200010];

int main(){
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    int now = 0;
    rep(i, k) {
        while (s[now] == 'x') now++;
        l[i] = now;
        now += c+1;
    }
    now = n-1;
    rrep(i, k) {
        while (s[now] == 'x') now--;
        r[i] = now;
        now -= c+1;
    }



    // rep(i, n) cout << l[i] << " ";
    // cout << endl;
    
    // rep(i, n) cout << r[i] << " ";
    // cout << endl;

    rep(i, k) if (l[i] == r[i]) cout << l[i] + 1 << endl;

    return 0;
}
