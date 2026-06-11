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
int mod2(int n,int k){
	k=(k|(n-k));
	if(n==k)
		return 3;
	return 0;
}
void End(int pp){
	printf("%d\n",pp);
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
		End(1);
	else if(y&1)
		End(0);
	else if(x&2)
		End(2);
	else
		End(0);
	return 0;
}
