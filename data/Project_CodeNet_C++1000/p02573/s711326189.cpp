#include<bits/stdc++.h>
#define fr(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
using namespace std;
vector<int>v[2000001];
vector<int>parent(2000001,-1);
int R[2000001]={1};
ll ct=0;
int find(int a){
	//cout<<parent[a]<<endl;
	if(parent[a]<0)
	return a;
	return parent[a]=find(parent[a]);
}
void u(int a,int b){
	//cout<<a<<b<<endl;
	parent[a]=-(abs(parent[a])+abs(parent[b]));
	//cout<<parent[a]<<endl;
	if(R[a]>=R[b]){
			parent[b]=a;
			R[a]+=R[b];		
	}
	else{
		parent[a]=b;
		R[b]+=R[a];
	}
	// Rank decrease we can find in o(logn) max time;

}
int main()
{
//	freopen("in4.txt", "r", stdin); 
//    freopen("output4.txt", "w", stdout);

	ll n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		v[i].pb(i);
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		a=find(a);
		//cout<<a<<endl;
		b=find(b);
		//cout<<b<<endl;
		if(a!=b)
		u(a,b);
	}
	int maxi=INT_MIN;
	for(int i=1;i<=n;i++){
		//cout<<parent[i]<<" ";
		if(parent[i]<0){
			maxi=max(maxi,abs(parent[i]));
		}
	}
	cout<<maxi<<endl;
}