#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define int ll

ll fastpow(int v,  int p){
    v %= MOD;
    if (p == 0)return 1;
    if (p == 1)return v%MOD;
    long long ans = fastpow(v, p/2)%MOD;
    long long res = (ans * ans)%MOD;
    if(p&1)res = (res * v)%MOD;
    return res;

}

int32_t main(){
    FAST
    int n; cin >> n;
    int ans = fastpow(10, n);
    ans -= (2 * fastpow(9, n))%MOD;
    if(ans < 0)ans += MOD;
    ans += fastpow(8, n);
    ans %= MOD;
    cout << ans;;
    return 0;
}
