#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 998244353;
const ll INF = 1e18;
using namespace std;

ll func(vector<ll> arr){
    int n = arr.size();
    for(int i = 1; i < n; i++)  arr[i] += arr[i-1];
    ll tot = arr[n-1], ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, abs(tot - arr[i] - arr[i]));
    }
    return ans;
}

main(){    
    #ifdef XOX
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\Input.txt", "r", stdin);
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\OPT.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    ll ans = func(arr);
    cout << ans;
}