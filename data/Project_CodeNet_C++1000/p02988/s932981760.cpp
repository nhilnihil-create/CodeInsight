#include <bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll, ll>
#define pb push_back
#define rep0(i, n) for(ll i = 0;i<n;i++)
#define rep1(i, n) for(ll i = 1;i<n;i++)
#define all(v) v.begin(),v.end()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){cin >> arr[i];}
    int ans = 0;
    for(int i=1; i<n-1; i++){
        if((arr[i]>arr[i-1] && arr[i]<arr[i+1]) || (arr[i]<arr[i-1] && arr[i]>arr[i+1])){
            ans++;
        }
    }
    cout << ans;
}
 
int main()
{
    fast;
    solve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    return 0;
}