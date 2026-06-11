#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int f[maxn],ans;
int find(int x)
{
	if(f[x] == x)
	return x;
	else return f[x] = find(f[x]);
}
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i = 0 ; i < a ; i++){
		f[i] = i;
	}
	for(int i = 0 ; i < b ; i++){
		int u,v;
		cin>>u>>v;
		if(find(u)==find(v)) ans++;
		else{
			f[find(f[u])] = find(v);
		}
	}
	cout<<a-1-b+ans;
	return 0;
}