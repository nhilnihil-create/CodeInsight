#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define mod 1000000007
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dx8[]={1,-1,0,0,1,1,-1,-1};
int dy8[]={0,0,1,-1,1,-1,1,-1};

ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinvfermat(ll a, ll m)
{
	return binexp(a, m - 2, m);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}
 
void subset(ll val[],ll sum,ll n){


   bool dp[n+1][sum+1];
   memset(dp,false,sizeof dp);

   for(ll i=0;i<=n;i++){
   	for(ll j=0;j<=sum;j++){
   		if(i==0)dp[i][j]=false;

   		 if(j==0)dp[i][j]=true;

   	}
   }
   for(ll i=1;i<=n;i++){
   	for(ll j=1;j<=sum;j++){
   		if(val[i-1]<=j){
   			dp[i][j]=dp[i-1][j-val[i-1]]||dp[i-1][j];

   		}
   		else
   			dp[i][j]=dp[i-1][j];

   	}
   }
   vector<bool> v;
   ll ans=INT_MAX;

   for(ll i=0;i<=sum/2;i++){
   	if(dp[n][i]==true){
   		//cout<<i<<endl;

   		ans=min(ans,sum-2*i);

   	}
   }
   // ll ans=INT_MAX;
   // for(ll i=0;i<v.size();i++){
   // 	ans=min(ans,sum-2*v[i]);

   // }
cout<<ans<<endl;
return;




}
void solve(){

ll n;
cin>>n;
ll ans=n%1000;
if(ans==0){
	cout<<0<<endl;return;

}
ans=1000-ans;
cout<<ans<<endl;






return;
}




int main()
{  
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    fast;
    ll t;
    t=1;
   //cin>>t;
    while(t--){
    	solve();
    }
    
   
  



#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
return 0;
}