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

int power(int a,int x){
	if(x==0) return 1;
	int y=power(a,x/2);
	y=(y*y)%M;
	if(x%2==1) return((a*y)%M);
	return y;
}

int32_t main(){
	IOS;
	int n,k;
	cin>>n>>k;
	int a[n];
	int ans=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int x=0;
		int y=0;
		for(int j=i+1;j<n;j++) if(a[j]<a[i]) x++;
		for(int j=0;j<n;j++) if(a[j]<a[i]) y++;
		ans=(ans+(x*k)%M)%M;
		ans=(ans+(y*((k*(k-1)%M)*power(2,M-2)%M)%M)%M)%M;
	}
	cout<<ans<<endl;
}