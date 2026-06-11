#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
int power(int x, int y)
{
    if(y==0) return 1;
    else if(y%2==0)
        return power(x*x%MOD,y/2)%MOD;
    else return (x%MOD*power(x*x%MOD,y/2))%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n, k;
        cin >> n >> k;
        vector<int> ans(k + 1);
        int sum = 0;
        for(int i = k; i > 0; i--){
            ans[i] = power(k / i, n);
            for(int j = 2 * i; j <= k; j += i){
                ans[i] = (ans[i] - ans[j] + MOD) % MOD;
            }
            sum = (sum + (ans[i] * i) % MOD) % MOD;
        }
        cout << sum << '\n';
    }
}