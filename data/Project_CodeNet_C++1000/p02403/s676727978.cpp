#include <stdio.h>
int main(){
int n,m;
while(1){
scanf("%d%d",&n,&m);
if(n==0)return 0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("#");
}
printf("\n");
}
printf("\n");
}
}