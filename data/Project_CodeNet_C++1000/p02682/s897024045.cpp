

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

const int m=998244353;
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
		int a,b,c,k;cin>>a>>b>>c>>k;
		int sum=0;
		int cards=k;

		sum+=min(cards,a);
		cards-=min(cards,a);
		if(cards){
			//sum+=min(cards,a);
			cards-=min(cards,b);
		}
		if(cards)
			sum-=cards;
		cout<<sum<<"\n";

	
		
	
	

	
	

	return 0;
	
		
}
		
		

