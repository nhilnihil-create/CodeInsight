#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long m[100000][2];
int main(){
while(1){
long long n,k,i,j,x=0;
cin>>n>>k;
if(n==0&&k==0)break;
for(i=0;i<n;i++)cin>>m[i][0];
m[0][1]=m[0][0];
for(i=1;i<n;i++){
m[i][1]=m[i-1][1]+m[i][0];
}
x=m[k-1][1];
for(i=k;i<n;i++){
x=max(x,m[i][1]-m[i-k][1]);
}
cout<<x<<endl;
}
return 0;
}