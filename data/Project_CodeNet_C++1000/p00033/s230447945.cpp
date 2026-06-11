#include<stdio.h>
main(){
int i,j,n;
scanf("%d",&n);
int a[n][10],b,c;
for(i=0;i<n;i++)
for(j=0;j<10;j++)
scanf("%d",&a[i][j]);
for(i=0;i<n;i++){
b=0;
c=0;
for(j=0;j<10;j++)
if(a[i][j]>b)
b=a[i][j];
else if(a[i][j]>c)
c=a[i][j];
else
break;
if(j==10)
puts("YES");
else
puts("NO");
}
return 0;
}