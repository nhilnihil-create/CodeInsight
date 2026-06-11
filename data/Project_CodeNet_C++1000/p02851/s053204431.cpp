#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
ll a[N], sum[N];
unordered_map<ll, ll> mem;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("VLJUM.INP", "r", stdin);
        //freopen("VLJUM.OUT", "w", stdout);
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        ll cur = 0, ans = 0;
        mem[0]++;
        for (int i = 1; i <= n; i++){
                cur = cur + a[i];
                sum[i] = (cur - i) % k;
                if (i >= k) mem[sum[i - k]]--;
                ans += mem[(cur - i) % k];
                mem[(cur - i) % k]++;
        }
        cout << ans;
}
