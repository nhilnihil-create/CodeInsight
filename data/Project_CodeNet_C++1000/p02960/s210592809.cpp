#include<bits/stdc++.h>
using namespace std;
#define ll long long int              //cout<<fixed<<setprecision(9)<<double value; 
#define INF 1000000000000000007
#define pb emplace_back 
#define md 1000000007
#define all(s) s.begin(),s.end()
typedef vector<int> vi;
int gh[100005];
int d=13;
ll dp[100005][14];
ll getsum(int idx,int n,int sum){
	if(idx>n)return (sum==5);
	if(dp[idx][sum]!=-1)return dp[idx][sum];
	ll res=0;
	if(gh[idx]!=-1){
		res+=getsum(idx+1,n,(sum*10+gh[idx])%d);
	}
	else{
		for(int i=0;i<=9;i++){
			res+=getsum(idx+1,n,(sum*10+i)%d);
		}
	}
	/*for(int i=0;i<=limit;i++){
		if(i<limit||flag){
			res+=getsum(idx+1,n,(sum+i)%d,true);
		}
		else{
			res+=getsum(idx+1,n,(sum+i)%d,false);
		}
	}*/
	return dp[idx][sum]=res%md;
}
void solve(){
	string b;
	cin>>b;
	//cin>>d;
	for(int i=0;i<b.size();i++){
		if(b[i]=='?')
		gh[i+1]=-1;
		else
		gh[i+1]=b[i]-'0';
	}
	memset(dp,-1,sizeof dp);
    ll r=getsum(1,b.size(),0);
   cout<<(r)%md<<"\n";
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
   int t=1;
  // cin>>t;
     while(t--){
     	solve();
	 }
     return 0;
}
