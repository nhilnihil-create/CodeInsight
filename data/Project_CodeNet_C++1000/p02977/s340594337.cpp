#include <bits/stdc++.h> 
using namespace std;
 
 
int main()
{ int n,i,sum=0,m,s=0,x; scanf("%d",&n);
if(n==1){printf("No"); return 0;}
m=n;
while(m%2==0){m/=2;}
if(m==1){printf("No"); return 0;}
m=n+1;
while(m){m/=2; s++;}  s--;
m=1; for(i=0;i<s;i++){m*=2;} int A[m];
for(i=0;i<m;i++){A[i]=i;}


printf("Yes\n");
//printf("%d\n",m);
for(i=m;i<n;i+=2){
printf("%d %d\n",i,i+1);
printf("1 %d\n",i);
printf("1 %d\n",i+n+1);
printf("%d %d\n",i+n,i+1+n);	
	
} 
if(n%2==0){
printf("%d %d\n",n,n-2);	
x=n^(n-2); x=x^1;
A[x]=2; A[2]=x;
printf("%d %d\n",2*n,x);	

	
	
	
}
for(i=1;i<m-1;i++){
printf("%d %d\n",A[i],A[i+1]);
	
	
} 
printf("%d %d\n",A[m-1],A[1]+n);
for(i=1;i<m-1;i++){
printf("%d %d\n",A[i]+n,A[i+1]+n);
	
	
} 


 
 
return 0;
}
