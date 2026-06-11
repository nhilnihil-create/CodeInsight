#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[200005];
int vis[200005];
int main(){
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int now=1;
	while(!vis[now]){
		vis[now]=v.size();
		v.push_back(now);
		now=a[now];
	}
	int s=v.size()-vis[now];
	int l=vis[now];
	if(l>k)
	cout<<v[k];
	else
	{
		k-=l;
		k%=s;
		cout<<v[l+k];
	}
}