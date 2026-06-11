#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!



vi arr={100,101,102,103,104,105};
    
    
// Simple combination Sum
bool calc(int sum,int n,vector<vi> &dp){
    if(sum==0){
        return 1;
    }
    if(n<=0 || sum<0){
        return false;
    }
    if(dp[sum][n]!=-1){return dp[sum][n];}
    
    return dp[sum][n]=calc(sum-arr[n-1],n,dp) || calc(sum,n-1,dp);
}
void solve(){

    int sum;
    cin>>sum;
    int n=6;
    vector<vector<int>> dp(sum+1,vector<int> (n+1,-1));
    
    cout<<calc(sum,n,dp)<<endl;
    
}





int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}