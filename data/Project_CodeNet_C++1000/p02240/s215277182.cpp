#include<bits/stdc++.h>
//cout<<setprecision(1)<<fixed<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=100000;
const int INF = 0x3f3f3f3f;
#define eps 1e-7
//#define Kongxiangzhouye
//int n,m;
//int e;
//int begin[301010];
//int next[301010];
//int to[301010];

int par[101010];

int find(int x){
    if(x!=par[x])
        par[x] = find(par[x]);
    return par[x]; 
}

int unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)
		par[y]=x;
}

void init(int n){
	for(int i=0;i<=n;i++){
		par[i]=i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	#ifdef Kongxiangzhouye
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n,m,q;
	while(cin>>n>>m){
		init(n);
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			unite(a,b);
		}
		cin>>q;
		for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			if(find(a)==find(b))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}

	return 0;
}




