#include<iostream>
#include<cstdio>
using namespace std;

int main(){
while(1){
int n;
scanf("%d",&n);
if(n==0)break;
char f[1002];
for(int i=0;i<1002;i++)f[i]=(char)i;
for(int i=0;i<n;i++){
char c,d;
scanf("\n%c %c",&c,&d);
f[(int)c] = d;
}
int m;
scanf("%d",&m);
for(int i=0;i<m;i++){
char c;
scanf("\n%c",&c);
printf("%c",f[(int)c]);
}
printf("\n");
}
}