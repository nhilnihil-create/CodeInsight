#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
vector<int> parent(200005);
vector<int> s(200005);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a,int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		parent[b] = a;
		s[a] += s[b];
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		s[i] =1;
		parent[i] =i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		union_sets(x,y);
	}
	int nax = INT_MIN;
	for(int i=1;i<n+1;i++)
	{
		nax = max(nax,s[i]);
	}
	cout<<nax<<endl;
}