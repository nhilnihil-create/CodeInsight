

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define w(t) int t;cin>>t;while(t--)
#define pb push_back
#define mk make_pair
#define ascSort(v) sort(v.begin(), v.end())
#define descSort(v) sort(v.begin(), v.end(), greater<int>())
#define ff first
#define ss second
#define pi pair<int,int>
#define vi vector<int>
#define umapi unordered_map<int,int>
#define INF 1000000007
//const int m=998244353;
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>PBDS;

void FIO(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
}



int32_t main(){
	
	//FIO();
	int n,m,x;cin>>n>>m>>x;
	int c[n];
	int a[n][m];
	for(int i=0; i<n; i++){
		cin>>c[i];
		for(int j=0; j<m; j++)
			cin>>a[i][j];
	}
	int mini=INF;
	for(int i=1; i<=(1<<n); i++){
		int cost=0,t[m]={};
		for(int j=0; (1<<j)<=i; j++){
			if(i&(1<<j)){
				cost+=c[j];
				for(int k=0; k<m; k++){
					t[k]+=a[j][k];
				}
			}
		}
		bool good=true;
		for(int k=0; k<m; k++){
			if(t[k]<x)
				good=false;
		}
		if(good)
			mini=min(mini,cost);
	}
	if(mini==INF)
		cout<<"-1\n";
	else
		cout<<mini<<"\n";
	return 0;
		
}
		
		

