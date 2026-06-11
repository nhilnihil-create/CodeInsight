#include<bits/stdc++.h>
#define fi first #define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 1e6;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, a[MAXN], d[MAXN], f[MAXN], l[MAXN], r[MAXN], top = 0;

void update(int i, int val){
    for (; i <= n; i += i & -i) f[i] = max (f[i], val);
}

int get(int l, int r){
    int res = 0;
    while (r >= l){
        if (r - (r & -r) >= l){
            res = max (res, f[r]);
            r -= r & -r;
        }
        else {
            res = max (res, a[r]);
            r--;
        }
    }
    return res;
}

int bs1(int hi, int i){
    int lo = 1, val = a[i], pre = hi;
    while (lo < hi){
        int mid = (lo + hi) / 2;
        if (get(mid, pre - 1) < a[i]) hi = mid;
        else lo = mid + 1;
    }
    return hi;
}

int bs2(int lo, int i){
    int hi = n, pre = lo;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        if (get(pre + 1, mid) < a[i]) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main(){
    #define TASK "ABC"
    #ifndef ONLINE_JUDGE
    freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
    #endif ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) update(i, a[i]);

    int top = 0;
    for (int i = 1; i <= n; i++){
        while (top > 0 && a[d[top]] <= a[i]) top--;
        l[i] = d[top] + 1;
        d[++top] = i;
    }

    top = 0, d[top] = n + 1;
    for (int i = n; i >= 1; i--){
        while (top > 0 && a[d[top]] <= a[i]) top--;
        r[i] = d[top] - 1;
        d[++top] = i;
    }

    long long ans = 0;

   // cerr << get(1, 2);

    for (int i = 1; i <= n; i++){
        int pos1 = l[i] - 1, pos2 = r[i] + 1;
        int pos3 = bs1(pos1, i), pos4 = bs2(pos2, i);

    //    cerr << i << ' ' << l[i] << ' ' << r[i] << ' ' << pos3 << ' ' << pos4 << '\n';

        int num = 0;

        if (pos3 > 0 && pos3 < l[i]) ans += 1ll * a[i] * (l[i] - pos3) * (r[i] - i + 1);

        if (pos4 <= n && pos4 > r[i]) ans += 1ll * a[i] * (pos4 - r[i]) * (i - l[i] + 1);

        if (pos3 > 0 && pos3 < l[i]) num += (l[i] - pos3) * (r[i] - i + 1);

        if (pos4 <= n && pos4 > r[i]) num += (pos4 - l[i]) * (i - r[i] + 1);

   //     ans += 1ll * a[i] * ((l[i] - pos3) * (r[i] - i + 1) + (pos4 - l[i]) * (i - l[i] + 1));
   //     cout << a[i] << ' ' << num << '\n';
    }

    cout << ans;

    return 0;
}
