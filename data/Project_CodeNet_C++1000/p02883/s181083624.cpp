#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
ll n, k, a[N], b[N];
bool chk(ll mid){
        ll res = 0;
        for (int i = 1; i <= n; i++){
                ll x = mid / b[i];
                if (a[i] > x) res = res + a[i] - x;
        }
        return (res <= k);
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("WALKING.INP", "r")){
                freopen("WALKING.INP", "r", stdin);
                freopen("WALKING.OUT", "w", stdout);
        }
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
                cin >> b[i];
        }
        sort(a + 1, a + n + 1, greater<ll>());
        sort(b + 1, b + n + 1);
        ll l = 0, h = 1e18;
        while (l <= h){
                ll mid = (l + h) >> 1;
                if (chk(mid)) h = mid - 1;
                else l = mid + 1;
        }
        cout << l;
}
