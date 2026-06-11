#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const int MAXN = 500005;
using namespace std;
int arr[MAXN],dp[MAXN];
int main() {
   /*ifstream cin("input.txt");
   ofstream cout("output.txt");*/
   fast_io;
   bool flag=true;
   std::vector<ll> suffix;
   ll n,mini=INT_MAX;cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++){
   		cin>>arr[i];
   }
   for(int i=n-1;i>=0;i--){
   		mini=min(mini,arr[i]);
   		suffix.pb(mini);
   }
   reverse(suffix.begin(),suffix.end());
   for(int i=0;i<n-1;i++){
   		if(arr[i]>suffix[i+1]&&abs(arr[i]-suffix[i+1])>=2){
   			flag=false;
   			break;
   		}
   }
   if(flag){
   		cout<<"Yes"<<endl;
   }
   else{
   		cout<<"No"<<endl;
   }
   return 0;
}


   	

