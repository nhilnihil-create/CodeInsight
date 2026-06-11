#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 5e5 + 5;
ll l[N], r[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("VLJUM.INP", "r")){
                freopen("VLJUM.INP", "r", stdin);
                freopen("VLJUM.OUT", "w", stdout);
        }
        ll n, k, c;
        cin >> n >> k >> c;
        string s;
        cin >> s;
        s = " " + s;
        set<ll> sr;
        set<ll, greater<ll>> sl;
        for (int i = 1; i <= n; i++){
                if (s[i] == 'o') {
                        sl.insert(i);
                        sr.insert(i);
                }
        }
        sl.insert(-1e18);
        sr.insert(1e18);
        unordered_map<ll,ll> dp;
        dp[-1e18] = 0;
        for (int i = 1; i <= n; i++){
                if (s[i] == 'o'){
                        dp[i] = dp[*(sl.lower_bound(i - c - 1))] + 1;
                        if (l[dp[i]] == 0) {
                                l[dp[i]] = i;
                        }
                        if (dp[i] > k) return 0;
                }
        }
        dp.clear();
        dp[1e18] = k + 1;
        for (int i = n; i >= 1; i--){
                if (s[i] == 'o'){
                        dp[i] = dp[*(sr.lower_bound(i + c + 1))] - 1;
                        if (r[dp[i]] == 0){
                                r[dp[i]] = i;
                        }
                }
        }
        for (int i = 1; i <= k; i++){
                if (l[i] == r[i]) cout << l[i] << endl;
        }
}
/*
*/
