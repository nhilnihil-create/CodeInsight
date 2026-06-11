#include<bits/stdc++.h>

#define mu(x) (1 << (x))
#define maxn 100005

using namespace std;
typedef long long ll;

int n;

int a[maxn];

int p[maxn][20];
int f[maxn];

void RMQ(){
    for (int i = 0; i <= n + 1; ++i)
        p[i][0] = a[i];

    for (int j = 1; j < 20; ++j)
        for (int i = 0; i <= n + 1; ++i)
            if (i + mu(j) <= n + 2)
                p[i][j] = max(p[i][j - 1], p[i + mu(j - 1)][j - 1]);

    for (int i = 1; i <= n + 1; ++i)
        for (int j = 0; j < 20; ++j)
            if (mu(j) <= i) f[i] = j;
}

int Max(int i, int j){

    return max(p[i][f[j -  i]], p[j - mu(f[j - i]) + 1][f[j - i]]);
}

int tkr(int l, int r, int k){
    int i = l;
    while (l < r){
        int mid = (l + r) / 2;
        if (Max(i, mid) > k) r = mid;
        else l = mid + 1;
    }
    return r;
}

int tkl(int l, int r, int k){
    int j = r;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (Max(mid, j) >= k) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main(){
  //  #define TASK "ABC"
    //freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[n + 1] = n + 1;

    RMQ();

    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        int r1 = tkr(i + 1, n + 1, a[i]), r2 = tkr(r1 + 1, n + 1, a[i]);
        int l1 = tkl(0, i - 1, a[i]), l2 = tkl(0, l1 - 1, a[i]);

        ll ret = 0;

        ret += 1ll * (r2 - r1) * (i - l1);
        ret += 1ll * (r1 - i) * (l1 - l2);
        ans += ret * a[i];
    }
    cout << ans;
    return 0;
}
