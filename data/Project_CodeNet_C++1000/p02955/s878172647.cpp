#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 5e2 + 5;
ll a[N], b[N], n, k;
bool chk(ll x){
        for (int i = 1; i <= n; i++){
                b[i] = a[i] % x;
        }
        sort(b + 1, b + n + 1);
        ll l = 1, r = n;
        ll cnt = 0;
        while (l < r){
                if (b[l] == 0) {
                        l++;
                        continue;
                }
                if (b[l] == (x - b[r])){
                        cnt += b[l];
                        r--;
                        l++;
                }
                else if (b[l] < (x - b[r])){
                        cnt += b[l];
                        b[r] += b[l];
                        l++;
                } else {
                        cnt += (x - b[r]);
                        b[l] -= (x - b[r]);
                        r--;
                }
        }
        return (cnt <= k);
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        ll sum = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
                sum += a[i];
        }
        ll ans = 1;
        for (int i = 1; i * i <= sum; i++){
                if (sum % i == 0) {
                        ll x = sum / i;
                        if (chk(x)) ans = max(ans, x * 1ll);
                        if (chk(i)) ans = max(ans, i * 1ll);
                }
        }
        cout << ans;
}
