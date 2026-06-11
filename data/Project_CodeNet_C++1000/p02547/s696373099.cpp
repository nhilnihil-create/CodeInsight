#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int flag = 0;
    for(int i= 1, x, y; i <= n; i++){
        cin >> x >> y;
        if(x == y){
            ans++;
        }else{
            ans = 0;
        }
        flag |= (ans == 3);
    }
    cout << (flag ? "Yes\n" : "No\n");
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}