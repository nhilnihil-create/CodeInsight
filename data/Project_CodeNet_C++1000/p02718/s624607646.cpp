#include<bits/stdc++.h>
using namespace std;
# define ld long double
int main()
{

	int n,m,s=0;
	cin>>n>>m;
	
	vector<int >v(n);
	
	for(auto &x:v)cin>>x,s+=x;
	
		ld t=(ld)s/(ld)(4*m);
		
		int ans=0;
		for(auto x:v)
		{
			if(x>=t)ans++;
		}
		
		if(ans>=m)cout<<"Yes";
		else
		cout<<"No";


	return 0;
}