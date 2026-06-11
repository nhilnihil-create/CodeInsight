#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

ll cnt[10][10];
int N;
int res;

void dfs(ll l, ll r) {
    if (l + r <= N) res++;
    else return;
    rep(i, 10) {
        dfs((l + i) * 10, r);
    }
}
int main()
{
    cin >> N;
    ll ans = 0;

    repd(l, 1, 10) {
        repd(r, 1, 10) {
            dfs(r * 10, l);
            cnt[l][r] += res;
            res = 0;
            if (l == r) cnt[l][r] += 1;
        }
    }
/*
    repd(i, 1, 10) {
        repd(j, 1, 10) {
            cout << i << " " << j << " : " << cnt[i][j] << endl;
        }
    }
*/
    repd(i, 1, N + 1) {
        if (i <= 9) {
            ans += cnt[i][i];
        }
        else {
            int r = i % 10, tmp = i, l;
            while (tmp) {
                l = tmp % 10;
                tmp /= 10;
            }
            // cout << i << " >> " << l << " " << r << endl;
            ans += cnt[l][r];
        }
    }

    cout << ans << endl;
    return 0;
}