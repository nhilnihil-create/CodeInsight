#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define umapi unordered_map<ll, ll>
#define umapc unordered_map<char, int>
#define endl "\n"
#define pui pair<int, pair<int,int> >
using namespace std;
 
 
void solve(){
    
    int n;
    cin>>n;

    vecl arr(n);
    bool zer0 = false;
    rep(i,n) {
        cin>>arr[i];
        if(arr[i] == 0) {
            zer0 = true;
        }
    }

    if(zer0) {
        cout<<0;
        return ;
    }

    int64_t ans = 1;

    rep(i,n) {
       // cout<<ans<<" ";
        if(ans  > 1000000000000000000 / arr[i]) {
            ans = -1;
            break;
        } else {
            ans = ans * arr[i];
        }
       // cout<<ans<<endl;
    }

    cout<<ans;


   
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

