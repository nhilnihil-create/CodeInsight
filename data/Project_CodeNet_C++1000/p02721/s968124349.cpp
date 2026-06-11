#include<bits/stdc++.h>
#include<cassert>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds; 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define inf INT_MAX
#define llinf LONG_LONG_MAX

const int MAXN=2e6+1;
const int M=1e9+7;
const int N=6e6+6;

void solve(){
	int n,k,c;
	sfi(n) sfi(k) sfi(c)

	vector<int> dp(n+1,0),dp1(n+1,0),v(n);

	string s;
	cin>>s;

	f(i,0,n){
		cin>>v[i];
	}

	int maxi=0,ind=0;

	int cnt=0;

	f(i,0,n){

		while((i-ind)>=(c+1)){
			maxi=max(maxi,dp[ind]);
			ind++;
		}
		if(s[i]=='x'){
			dp[i]=maxi;
		}
		else{
			cnt++;
			dp[i]=1+maxi;
		}

		if(i!=0){
			dp[i]=max(dp[i],dp[i-1]);
		}
		//cout<<dp[i]<<" "<<ind<<endl;
	}

	ind=n-1,maxi=0;

	dp1[n]=0;

	for(int i=n-1;i>=0;i--){
		while((ind-i)>=(c+1)){
			maxi=max(maxi,dp1[ind]);
			ind--;
		}
		if(s[i]=='x'){
			dp1[i]=maxi;
		}
		else{
			dp1[i]=1+maxi;
		}

		if(i!=n-1){
			dp1[i]=max(dp1[i],dp1[i+1]);
		}
	}

	vector<int> fin;

	int util[n+2]={0};

	for(int i=-1;i+c+1<=n;i++){
		//cout<<i<<endl;
		int val1=(i==-1)?0:dp[i];
		int val2=dp1[i+c+1];

		//cout<<i<<" "<<i+c+1<<" "<<val1<<" "<<val2<<endl;
		if(val1+val2>=(k)){
			util[i+1]+=1;
			util[i+c+1]-=1;
		}

		
	}

	int tot=0;



	for(int i=0;i<n;i++){
		tot+=util[i];

		int val1=(i-1)==-1?0:dp[i-1];
		int val2=(i+1)==n?0:dp1[i+1];

		//cout<<tot<<" "<<val1<<" "<<val2<<endl;
		if(s[i]=='o' && tot<=0 && val1<k && val2<k){
			fin.push_back(i);
		}
	}

	if(c==0){
		if(cnt==k){
			for(int i=0;i<n;i++){
				if(s[i]=='o'){
					cout<<i+1<<endl;
				}
			}
		}
		else{

		}
		return;
	}


	for(int x:fin){
		cout<<x+1<<"\n";
	}
	//cout<<"**";
	

}
int main(){	
	
	solve();
	return 0;	
}