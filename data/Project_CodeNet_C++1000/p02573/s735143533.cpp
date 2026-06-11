#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const int INF=0x3f3f3f3f;
const int N=1e6+7;
const int mod=1e9+7;
int maxn,minn;
int T,n,m,q;

int pre[N];

void init(){
	for(int i = 1; i <= n; i ++ ){
		pre[i] = i;
	}
}

int find(int a){
	if(pre[a] == a)	return a;
	return pre[a] = find(pre[a]);
}

void join(int a,int b){
	int aa = find(a);
	int bb = find(b);
	if(aa != bb){
		pre[aa] = pre[bb];
	} 
}


int main(){
	int u,v;
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i ++ ){
		scanf("%d%d",&u,&v);
		join(u,v);
	}
	map<int,int>mp;
	maxn = 0;
	for(int i = 1; i <= n; i ++ ){
		mp[find(i)] ++ ;
		maxn = max(maxn, mp[pre[i]]);
	}
	cout << maxn << endl;
	
	
	
	


	return 0;
}

