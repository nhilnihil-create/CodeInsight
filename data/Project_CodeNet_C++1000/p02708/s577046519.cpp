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

int32_t main(){
    FAST
    int n, k; cin >> n >> k;
    int ans = 1;
    int highest[n + 1];
    mm(highest);
    int a = n;
    int sum = 0;
    for(int i = 1; i <= n + 1; i++){
        sum += a;
        sum %= MOD;
        highest[i] = sum;
        a--;
    }
    for(int i = k; i <= n; i++){
        int l = ((i * (i - 1))/2)%MOD;
        int a = highest[i] - l;
        a++;
        a %= MOD;
        if(a < 0)a += MOD;
        ans = (ans + a)%MOD;
    }
    cout << ans;
    return 0;
}
