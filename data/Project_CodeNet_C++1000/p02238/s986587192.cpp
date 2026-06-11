#include<iostream>
#include<list>
using namespace std;

#define MAX_N 101

int counter;
int d[MAX_N];
int f[MAX_N];

void DFS(list<int>* G, int n){
	counter++;
	d[n] = counter;
	list<int>::iterator it;
	for(it=G[n].begin(); it!=G[n].end(); it++){
		if(d[*it-1]==0) DFS(G, *it-1);
	}
	counter++;
	f[n] = counter;
}

int main()
{
	counter = 0;
	for(int i=0; i<MAX_N; i++) d[i]=f[i]=0;
	int n;cin>>n;
	list<int> G[n];
	
	// input Graph data
	for(int i=0; i<n; i++){
		int u, k, v;
		cin >> u >> k;
		for(int j=0; j<k; j++){
			cin >> v;
			G[u-1].push_back(v);
		}
	}
	// DFS
	for(int i=0; i<n; i++){
		if(d[i]==0){
			DFS(G, i);
		}
	}
	// Output Result
	for(int i=0; i<n; i++){
		cout << i+1 << " " << d[i] << " " << f[i] << endl;
	}

	return 0;
}