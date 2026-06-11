#include<bits/stdc++.h>
using namespace std;

int n,m;
int pre[200050];
int b[200050] = {0};

void init()
{
	for(int i = 0;i<=200050;++i)
	    pre[i] = i;
}

int find(int x)
{
	if(x == pre[x]) return x;
	int root = find(pre[x]);//压缩路径 
	return pre[x] = root;
}

void join(int x,int y)
{
	int fx = find(x),fy = find(y);
	
	if(fx != fy){
		pre[fx] = fy;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		join(x,y);
		
//		for(int i = 1;i<=n;++i){
//			cout<<pre[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i = 1;i<=n;++i){
		b[find(i)]++;
	}
	int maxn = 0;
	for(int i = 1;i<=n;++i)
	    if(b[i]>maxn) maxn = b[i];
	    
	cout<<maxn<<endl;
	return 0;
}