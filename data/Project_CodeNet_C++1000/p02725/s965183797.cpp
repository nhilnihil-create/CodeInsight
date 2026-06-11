

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
#define PI 3.14159265
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
	
		int k,n;cin>>k>>n;
		vi a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		int mn=0;
		for(int i=1; i<n; i++){
			mn=max(mn,a[i]-a[i-1]);
		}
		mn=max(mn,k-a[n-1]+a[0]);
		cout<<k-mn;
	return 0;
	
		
}
