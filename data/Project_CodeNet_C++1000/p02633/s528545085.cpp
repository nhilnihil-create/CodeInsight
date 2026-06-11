#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <complex>
#include <bitset>
#include <cmath>
#include <stack>

#define ll long long
#define PII pair<ll,pair<ll,ll>>
#define print(arr,s,n) for (int i = s; i < n; ++i) cout<<arr[i]<<" "; cout<<endl;
#define ordered_set tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

using namespace std;
using namespace __gnu_pbds;

void solve()
{
	int n;
	cin>>n;	
	int k = n;
	int ans = 1;
	while((k%360))
	{
		k+=n;
		ans++;
	}
	cout<<ans<<endl;
}

int main()
{ 

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}