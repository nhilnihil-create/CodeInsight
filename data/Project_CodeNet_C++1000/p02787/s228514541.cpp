#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int h,n;
    cin >> h >> n;
    vector<pair<int,int>> magic(n);
    for(int i=0;i<n;i++) cin >> magic[i].first >> magic[i].second;
    sort(magic.begin(),magic.end());
    vi dp(h+magic[n-1].first,1e9);
    dp[0]=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            dp[i+magic[j].first]=min(dp[i+magic[j].first],dp[i]+magic[j].second);
        }
    }
    int ans=1e9;
    for(int i=h;i<h+magic[n-1].first;i++){
        ans=min(ans,dp[i]);
    }
    cout << ans << endl;
}