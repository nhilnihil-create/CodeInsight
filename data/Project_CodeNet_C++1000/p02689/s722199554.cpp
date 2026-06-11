#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int>h(100000);
vector<bool>g(100000,1);

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>h[i];
	
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		--a,--b;
		if(h[a]<=h[b])g[a]=0;
		if(h[b]<=h[a])g[b]=0;
	}
	
	for(int i=0;i<n;i++)cnt+=g[i];
	cout<<cnt;
	return 0;
}

