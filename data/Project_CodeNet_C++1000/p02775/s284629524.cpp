#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;

int32_t main(){
    IOS;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int n=s.size();
    int dp[n][2];
    memset(dp,M,sizeof(dp));
    dp[0][0]=(s[0]-'0');
    dp[0][1]=(10-(s[0]-'0'));
    for(int i=1;i<n;i++){
    	dp[i][0]=min(dp[i-1][0]+s[i]-'0',dp[i-1][1]+1+s[i]-'0');
    	dp[i][1]=min(dp[i-1][0]+10-(s[i]-'0'),dp[i-1][1]+9-(s[i]-'0'));
    }
    cout<<min(dp[n-1][0],dp[n-1][1]+1);
}