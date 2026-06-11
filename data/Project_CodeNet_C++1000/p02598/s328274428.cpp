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
vector<int> vis(N);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int &it : a){
            cin >> it;
        }
        int l = 1, r = 1e10;
        while(l <= r){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int &it : a){
                cnt += (it / mid) - (it % mid == 0);
            }
            if(cnt <= k){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
}