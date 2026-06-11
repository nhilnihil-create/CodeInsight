#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int x,y,a,b,c;
	int i,j,k;
	scanf("%d %d %d %d %d",&x,&y,&a,&b,&c);
	
	long long p[a],q[b],r[c],res[x+y+x+y];
	for(i = 0;i < 2*x + 2*y ;i++)
		res[i] = 0;
	
	i = 0;
	while(i < a)
		scanf("%lld",&p[i++]);
	sort(p,p+a);
	j = a-1;
	for(k = 0;k < x;k++)
		res[k] = p[j--]; 
		
	i = 0;
	while(i < b)
		scanf("%lld",&q[i++]);
	sort(q,q+b);
	j = b-1;
	int e = k + y;
	for(k;k < e;k++)
		res[k] = q[j--]; 
		
	
	i = 0;
	while(i < c)
		scanf("%lld",&r[i++]);
	sort(r,r+c);
	int f = k + x + y;
	j = c - 1;
	for(k;k < f && j >= 0;k++)
		res[k] = r[j--]; 
	
	sort(res,res+2*x+2*y,greater<int>());
/*	
	for(i = 0;i < 2*x + 2*y;i++)
		printf("%d ",res[i]);
*/	
	for(i = 1;i<x+y;i++)
		res[i] += res[i-1];
		
		
	
		
	printf("%lld",res[x+y-1]);
	return 0;
	
	
		
	
} 