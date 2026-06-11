#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;

struct node{
	int a,b,c,d;
}t[60]; 

int n,m,q,ans,s[20];

void dfs(int nw,int st){
	if(nw > n){
		int res = 0;
		for(int i = 1;i <= q;++i){
			if(s[t[i].b] - s[t[i].a] == t[i].c)
				res += t[i].d;
		}
		ans = max(ans,res);
		return ;
	}
	for(int i = st;i <= m;++i){
		s[nw] = i;
		dfs(nw+1,i);
	}
	return ;
}
int main(){
	cin >> n >> m >> q;
	for(int i = 1;i <= q;i++){
		scanf("%d %d %d %d",&t[i].a,&t[i].b,&t[i].c,&t[i].d);
	}
	ans = -inf;
	
	dfs(1,1);
	
	cout<<ans<<endl;
    return 0;
}