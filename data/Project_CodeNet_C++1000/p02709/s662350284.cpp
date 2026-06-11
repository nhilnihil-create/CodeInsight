#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2002;
pair<int,int> arr[N];
int dp[N][N];

int solve(int i,int l,int r)
{
    if(l > r) return 0;

    int & ans = dp[l][r];
    if(ans != -1) return ans;

    ans = 0;

    // place at left
    ans = arr[i].first*abs(l - arr[i].second) + solve(i+1,l+1,r);

    // place at right
    ans = max(ans,arr[i].first*abs(r - arr[i].second) + solve(i+1,l,r-1));

    return ans;

}

int32_t main() {
    
    int n; cin>>n;
    memset(dp,-1,sizeof dp);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i].first;
        arr[i].second = i;
    }

    sort(arr,arr + n);
    reverse(arr,arr + n);

    cout<<solve(0,0,n-1);


}
