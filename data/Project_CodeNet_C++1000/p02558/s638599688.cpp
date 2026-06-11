#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sz5 100005

int par[2*sz5];

int parent(int idx){
	if(par[idx]!=idx)
		par[idx]=parent(par[idx]);
	return par[idx];
}

int main() {
	FAST
	
	int n,q,x,y,ch,la;
	cin>>n>>q;
	for(la=1;la<=n;la++)
		par[la]=la;

	while (q--)
	{
		cin>>ch>>x>>y;
		if(ch==0){
			par[parent(x)]=parent(y);
		}else{
			if(parent(x) == parent(y))
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}