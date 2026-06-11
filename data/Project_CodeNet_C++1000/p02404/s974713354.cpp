#include<stdio.h>
int main(){
int a[100],b[100],i=0;
do{
scanf("%d %d",&a[i],&b[i]);
i++;
}while(a[i-1]!=0||b[i-1]!=0);
for(int x=0;x<i-1;x++){
for(int y=0;y<a[x];y++){
if(y==0||y==a[x]-1){
for(int z=0;z<b[x];z++){
printf("#");
}
}
else{
for(int z=0;z<b[x];z++){
if(z==0||z==b[x]-1)printf("#");
else printf(".");
}
}
printf("\n");
}
printf("\n");
}
}