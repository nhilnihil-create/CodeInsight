

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
const int mod=998244353;
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
bool cmp(int a, int b){
	return a>b;
}
int32_t main(){
	
	FIO();
	
		int n,m;cin>>n>>m;
		vi a(n);int tot=0;
		for(int i=0; i<n; i++){
			cin>>a[i];tot+=a[i];
		}
		sort(a.begin(), a.end(), cmp);
		if(a[m-1]<(tot+4*m-1)/(4*m))
			cout<<"No";
		else
			cout<<"Yes";
	
	return 0;
	
		
}
