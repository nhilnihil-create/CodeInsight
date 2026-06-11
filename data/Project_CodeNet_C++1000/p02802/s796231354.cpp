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
	
	int n,m;
	cin>>n>>m;
	vector<int> v(n+1);
	vector<bool> ac(n+1);
	int c_ans=0;
	int p_ans=0;

	for(int i=0;i<m;i++){
		int x;string r;
		cin>>x>>r;
		if(r=="AC"){
			if(!ac[x]){
				p_ans+=v[x];
				c_ans++;
				ac[x]=1;
				v[x]=0;
			}
		}
		else{
			v[x]++;
		}
	}

	cout<<c_ans<<" "<<p_ans<<endl;

	return 0;
}