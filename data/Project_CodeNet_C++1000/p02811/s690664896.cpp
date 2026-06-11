#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define eps 1e-9
#define oo 1e7+5

using namespace std;

typedef unsigned long long ull;
typedef vector<pair<int,pair<int,int>>> dirgraph;
typedef vector<vector<int>> graph;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int k,x;
	cin>>k>>x;
	k*=500;
	if(k>=x)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}