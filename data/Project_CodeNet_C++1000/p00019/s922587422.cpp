#include<iostream>
using namespace std;
int main(){
long i,j,k,c,n,f[21]={0};
f[1]=j=1;
cin>>n;
for(k=1;k<=n;k++){
c=0;
for(i=1;i<=j+1;i++){
f[i]=f[i]*k+c;c=f[i]/10;
if(c){
f[i]%=10;if(i+1>j)j++;
}
}
}
while(j>0)cout<<f[j--];
cout<<endl;
return 0;
}