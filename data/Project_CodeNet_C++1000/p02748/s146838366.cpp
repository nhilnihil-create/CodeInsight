#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#define endl '\n'
using namespace std;
int main()
{
	int a,b,m;
	cin>>a>>b>>m;
	vector<int> r(a);
	vector<int> micro(b);
	for(int i = 0; i<a; i++)
		cin>>r[i];
	for(int i = 0; i<b; i++)
		cin>>micro[i];
	int A = *min_element( r.begin(),r.end() );
	int B = *min_element( micro.begin(),micro.end() );
	int ans = A + B;
	for(int i = 0; i<m; i++)
	{
		int x,y,c;
		cin>>x>>y>>c;x--,y--;
		ans = min(ans,r[x]+micro[y]-c);
	}
	cout<<ans<<endl;
	return 0;
}
