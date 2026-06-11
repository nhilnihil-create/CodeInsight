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

void make(int a[],int n){
	int mx=-1;
	for(int i=0;i<n;i++){mx=max(mx,a[i]);a[i]=mx;}
}

int find(int a[],int n){
	int mx=-1;
	for(int i=0;i<n;i++){
		mx=max(a[i],mx);
	}
	return(mx);
}

int32_t main(){
    IOS;
    int n,t;
    cin>>n>>t;
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
    	int x,y;
    	cin>>x>>y;
    	p[i]={x,y};
    }
    sort(p,p+n);
    int dp[t+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
    	for(int j=t-1;j>=0;j--){
    		int x=p[i].ff;
    		int y=p[i].ss;
    		if(j+x>=t) dp[t]=max(dp[t],dp[j]+y);
    		else{
    			dp[j+x]=max(dp[j+x],dp[j]+y);
    		}
    	}	
    	make(dp,t+1);
    }
    cout<<find(dp,t+1);
}