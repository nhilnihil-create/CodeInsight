#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int parent[N], siz[N];

void make_set(int v){
	parent[v] = v;
}

int find_set(int v){
	while(v!=parent[v])
		v = parent[v];
	return v;
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(siz[a] < siz[b])
			swap(a,b);
		parent[b] = a;
		siz[a] += siz[b];
	}
}

int32_t main() 
{ 
	fast;
	memset(siz, 0, sizeof siz);
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		make_set(i);
	while(q--){
		int t, u, v;
		cin>> t >> u >> v;
		if(t==0)
			union_sets(u,v);
		else{
			if(find_set(u) == find_set(v))
				cout<< 1 <<endl;
			else
				cout<< 0 <<endl;
			}
		}
			
} 

