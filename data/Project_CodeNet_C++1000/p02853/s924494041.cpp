#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m[210],x,y,ans;
int main(){
	m[1]=300000;
	m[2]=200000;
	m[3]=100000;
	scanf("%d%d",&x,&y);
	if(x==1&&y==1)
	   ans=m[x]+m[y]+400000;
	else
	    ans=m[x]+m[y];
	printf("%d\n",ans);



	return 0;
}
