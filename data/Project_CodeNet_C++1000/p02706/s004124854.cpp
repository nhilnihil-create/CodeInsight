

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
	
		int n,m;cin>>n>>m;
		vi a(m);
		int sum=0;
		for(int i=0; i<m; i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum>n)
			cout<<"-1\n";
		else
			cout<<n-sum<<"\n";
	
	return 0;
		
}
		
		

