#include <bits/stdc++.h>
#define simplify ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
using namespace std;

vector<pair<int,int>>arr;
int dp[2005][2005];
int n;
int solve(int pos,int left, int right){
    if(pos>=n)return 0;
    if(left>right)return -1e10;
    int &ans=dp[left][right];

    if(ans!=-1)return ans;
    int maxi1=solve(pos+1,left+1,right)+abs(arr[pos].second-left)*arr[pos].first;
    int maxi2=solve(pos+1,left,right-1)+abs(arr[pos].second-right)*arr[pos].first;
    
    return ans=max(maxi1,maxi2);

}

int32_t main(){

    simplify
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr.rbegin(),arr.rend());
    memset(dp,-1,sizeof dp);
    int ans=solve(0,0,n-1);
    cout<<ans;


    
    return 0;
}
