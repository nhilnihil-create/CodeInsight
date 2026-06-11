#include<bits/stdc++.h>
#define STDIO
#define MOD 1000000007
#define testbit(mask,i) (((mask)>>(i))&1)
#define setbit(mask,i) ((mask)|(1<<i))
#define delbit(mask,i) ((mask)^(1<<i))
#define lowbit(x) ((x)&(-x))
#define INF MOD
using namespace std;
int n;
int a[1000100];
int mod2(int n,int r){
	int delta=(r|(n-r));
	if(n==delta)
		return 3;
	return 0; 
}
void Out(int ans){
	printf("%d\n",ans);
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%1d",&a[i]);
		a[i]--;
	}
	int x=0,y=0;
	for(int i=0;i<n;i++){
		x^=(mod2(n-1,i)&a[i]);
		y|=a[i];
	}
	if(x&1)
		Out(1);
	else if(y&1)
		Out(0);
	else if(x&2)
		Out(2);
	else
		Out(0);
	return 0;
}
