#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100,inf=0x3f3f3f3f;
int n,a[maxn],b[maxn],c[maxn],ok=0;
bool dfs(int x,int y,int t){
	if(t==11) {
		ok=1;
	}
	if(a[t]>b[x-1]){
		b[x]=a[t];
		dfs(x+1,y,t+1);
	}
	if(a[t]>c[y-1]){
		c[y]=a[t];
		dfs(x,y+1,t+1);
	}

}
int main()
{
	//freopen("read.txt", "r", stdin);
	cin>>n;
	while(n--){
		for(int i=1;i<=10;i++)cin>>a[i];
		ok=0;
		dfs(1,1,1);
		if(ok==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	//fclose(stdin);
	return 0;
}