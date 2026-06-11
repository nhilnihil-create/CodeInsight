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

const int N = 1e5 + 5;
int dp[N];
bool cant[N];
int n;
int calc(int i){
    if(i > n)return 0;
    if(cant[i])return 0;
    if(i == n){
        return 1;
    }

    if(dp[i] != -1){
        return dp[i];
    }
    return dp[i] = ((calc(i + 1)%MOD) + calc(i + 2)%MOD)%MOD;
}
int32_t main(){
    FAST
    int m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        cant[a] = 1;
    }
    cout << calc(0);
    return 0;
}
