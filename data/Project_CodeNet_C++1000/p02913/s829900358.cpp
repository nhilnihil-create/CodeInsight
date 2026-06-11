#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 5e3 + 5;
ll mod = 1e9 + 7;
ll sum[N], fact[N], n;
bool chk(ll mid){
        map<ll,ll> mem;
        for (int i = mid; i <= n; i++){
                ll ha = (sum[i] - sum[i - mid] * fact[mid] + mod * mod) % mod;
                if (mem[ha] == 0) mem[ha] = i;
                else {
                        if (mem[ha] <= (i - mid)) {
                                return 1;
                        }
                }
        }
        return 0;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * 311 % mod;
        for (int i = 1; i <= n; i++){
                sum[i] = (sum[i - 1] * 311 + (s[i] - 'a') + 1) % mod;
        }
        ll l = 1, h = n / 2;
        while (l <= h){
                ll mid = (l + h) >> 1;
                if (chk(mid)) l = mid + 1;
                else h = mid - 1;
        }
        cout << h;
}
