#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;

int root[10010];
int rank[10010];

void init(int n){
	REP(i,n){
		root[i]=i;
		rank[i]=0;
	}
}

int find(int x){
	if(root[x]==x) return x;
	else return root[x]=find(root[x]);
}

void unite(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]){
		root[x]=y;
	}else{
		root[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

int main(void){
	int i;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n,q;
	cin >> n >> q;
	init(n);
	for(i=0;i<q;i++){
		int c,x,y;
		cin >> c >> x >> y;
		if(c==0) unite(x,y);
		else cout << same(x,y) << endl;
	}

	return 0;
}