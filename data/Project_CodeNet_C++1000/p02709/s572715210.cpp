#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 200005
#define INF 1e18
lli n;
lli dp[3000][3000];
vector <pair <lli,lli> > arr;
bool compare(pair <lli,lli> a, pair <lli,lli> b){
    if(a.first > b.first)
        return true;
    else if(a.first == b.first && a.second > b.second)
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    lli temp;
    for(lli i = 0; i<n; i++){
        cin>>temp;
        arr.push_back({temp,i+1});
    }
    sort(arr.begin(),arr.end(), compare);
    dp[0][0] = 0;
    for(lli i = 1; i<=n; i++){
        dp[i][0] = dp[i-1][0] + arr[i-1].first*(abs(arr[i-1].second-i));
    }
    for(lli i = 1; i<=n; i++){
        dp[0][i] = dp[0][i-1] + arr[i-1].first*(abs(arr[i-1].second-(n-i+1)));
    }
    lli candi1, candi2;
    for(lli i = 1; i<=n; i++){
        for(lli j = 1; j+i <=n; j++){
            candi1 = dp[i-1][j] + arr[i+j-1].first*(abs(arr[i+j-1].second-i));
            candi2 = dp[i][j-1] + arr[i+j-1].first*(abs(arr[i+j-1].second-(n-j+1)));
            dp[i][j] = max(candi1,candi2);
        }
    }
    lli ans = LONG_LONG_MIN;
    for(lli i = 0; i<=n; i++){
            lli j = n-i;
            ans = max(ans,dp[i][j]);
        //cout<<endl;
    }
    cout<<ans<<endl;
}
    