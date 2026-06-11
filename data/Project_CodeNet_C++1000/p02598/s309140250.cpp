#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define ll     long long
#define maxn   200005

int n, k;
int a[maxn];

bool f (int x) {
        ll cnt = 0;
        for(int i = 1; i <= n; ++ i) {
            cnt += (ll) (a[i] - 1LL) / x;
            if(cnt > k) return false;
        }
        return cnt <= k;
}

int main() {
        //freopen(".inp","r",stdin);

        cin >> n >> k;

        for(int i = 1; i <= n; ++ i)
            cin >> a[i];

        int lo = 0, hi = (int) 1e9 + 7;

        while(hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi;
}

