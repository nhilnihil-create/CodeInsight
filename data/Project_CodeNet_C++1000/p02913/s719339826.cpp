
/**
*   author:  akifpathan
*   created: Sunday 13.09.2020 03:56:48 PM
**/

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#ifdef LOCAL
#include "debug.h"
#else
#include<bits/stdc++.h>
using namespace std;
#define debug(x...)
#endif
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using ordered_set= tree<T, null_type, 
		less<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
template<class T> 		
using ordered_mset= tree<T, null_type, 
		less_equal<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
		
*/
 
/*
 
PBDS
-------------------------------------------------
			0 based indexing
-------------------------------------------------			 
1) insert(value)
2) erase(value)
3) order_of_key(value) // Number of items strictly smaller than value
4) *find_by_order(k) : K-th element in a set (counting from zero)
 
*/
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	

const ll base=31;

ll ara[6000],power[6000];

void solve()
{
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	s='.'+s;
	
	power[0]=1LL;
	for(int i=1;i<=n;i++) power[i]=power[i-1]*base;
	
	for(int i=1,j=n-1;i<=n;i++,j--)
	{
		ara[i]=ara[i-1]+power[j]*s[i];
	}
	
	int ans=0;
	
	for(int i=1;i<=n/2;i++)
	{
		map<ll,vector<int>>indx;
		
		for(int j=1;i+j-1<=n;j++)
		{
			ll temp=ara[i+j-1]-ara[j-1];
			temp*=power[j-1];
			
			indx[temp].push_back(j);
		}
		
		for(auto it: indx)
		{
			if(it.second.size()>=2)
			{
				if(it.second[0]+i<=it.second.back()) ans=i;
			}
		}
	}
	
	cout<<ans;
	
}		

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int testcase=1;
	//cin>>testcase;
	
	for(int i=1;i<=testcase;i++)
	{
		//cout<<"Case "<<i<<": ";
		solve();
	}
	
	#ifdef LOCAL
	cerr<<"\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
	#endif
	
	
	return 0;
}

