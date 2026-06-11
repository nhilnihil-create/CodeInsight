#include<iostream>
using namespace std;
int main(){
long n,a[31],i,j;
while(cin>>n){
if(n==0)break;
a[0]=1;
a[1]=1;
a[2]=a[1]+a[0];
a[3]=a[2]+a[1]+a[0];
for(i=4;i<=n;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
cout<<(a[n]-1)/3650+1<<endl;
}
return 0;
}