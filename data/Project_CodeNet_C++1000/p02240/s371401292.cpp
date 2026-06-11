#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100000;

int par[MAX_N];
int rank[MAX_N];

void initial(int n){		//?????????
	for(int i=0;i<n;i++){
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x){		//??¨??????????±???????
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y])
			rank[x]++;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

int main()
{
	int n,m,q;
	int a,b;
	cin >> n;
	cin >> m;
	initial(n);
	for(int i=0;i<m;i++){
		cin >> a;
		cin >> b;
		unite(a,b);
	}
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> a;
		cin >> b;
		if(same(a,b)){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
}