 #include <bits/stdc++.h>
using namespace std;
#define fr(i,k,n) for(int i=k;i<n;i++)
#define read(x) cin>>x
#define ll long long int
#define mod 1000000007 
#define print(x) cout<<x<<endl
#define pb(x) push_back(x)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() { 
    fastIO;
     ll t=1,n;
     //cin>>t;
     while(t--){
       cin>>n;
       pair<ll,ll> arr[10000];
         
       fr(i,0,n){
         cin>>arr[i].first;
         arr[i].second=i;
       }
       sort(arr,arr+n);
       reverse(arr,arr+n);
       ll ans=INT_MIN;
       vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
       dp[0][0]=0;
       for(int i=0;i<n;i++){
         for(int j=0;(i+j)<=n ;j++)
         { if(i+j ==n )
              ans=max( dp[i][j] ,ans )   ;
          else{ dp[i+1][j]=(ll)max(dp[i+1][j],(ll)dp[i][j]+abs(i -arr[i+j].second) *arr[i+j  ].first);
           dp[i][j+1]=(ll)max(dp[i][j+1],(ll)dp[i][j]+abs(n-j-1-arr[i+j].second) *arr[i+j  ].first);
            // cout<<arr[i+j].first<<dp[i][j+1] <<endl;
              }
                          
         }
       }
       cout<<ans<<endl;
         
         
     }
	 
	return 0;
}
