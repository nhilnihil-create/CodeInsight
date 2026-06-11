#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[51],y[51];
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	map<pair<int,int>,int>::iterator it;
	map<pair<int,int>,int> mp;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			if (dx || dy) mp[make_pair(dx,dy)]++;
		}
	int mx=0;
	for (it=mp.begin();it!=mp.end();it++)
		mx=max(mx,it->second);
	printf("%d\n",n-mx);
	return 0;
}