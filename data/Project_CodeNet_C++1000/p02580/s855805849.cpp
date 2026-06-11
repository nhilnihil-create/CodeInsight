#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   300005
#define mod    1000000007
#define ar2    array<int, 2>

ar2 a[maxn], b[maxn];
map <ar2, bool> d;

int dx[maxn], dy[maxn];

int main() {
        #ifndef ONLINE_JUDGE
            //freopen(".inp","r",stdin);
        #endif // ONLINE_JUDGE

        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        int n, m, k;
        cin >> n >> m >> k;

        for(int i = 1; i <= k; ++ i) {
            cin >> a[i][0] >> a[i][1];
            b[i] = {a[i][1], a[i][0]};
            d[a[i]] = 1;
        }

        sort(a + 1, a + k + 1);
        sort(b + 1, b + k + 1);

        int cx = 1, cy = 1;
        ar2 x = {0, 0}, y = {0, 0};

        for(int i = 1; i <= k; ++ i) {
            if(i == k || a[i][0] != a[i+1][0]) {
                x = max(x, {cx, a[i][0]});
                dx[a[i][0]] = cx;
                cx = 1;
            } else
                cx ++;
            if(i == k || b[i][0] != b[i+1][0]) {
                y = max(y, {cy, b[i][0]});
                dy[b[i][0]] = cy;
                cy = 1;
            } else
                cy ++;
        }

        int ret = 0;
        for(int i = 1; i <= k; ++ i) {
            int cnt = x[0] + dy[b[i][0]];
            if(d.count({x[1], b[i][0]})) cnt --;
            ret = max(ret, cnt);

            cnt = y[0] + dx[a[i][0]];
            if(d.count({a[i][0], y[1]})) cnt --;
            ret = max(ret, cnt);
        }
        cout << ret;
}



