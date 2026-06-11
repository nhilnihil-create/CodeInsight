#include<iostream>
using namespace std;

int main()
{
int a[4]={-1000000000,0,0,0},b[4],c;
cin>>a[1]>>a[2]>>a[3];
for(int i=1;i<4;i++){
b[i]=a[i];
for(int j=i;j>0;j--){
if(b[j]<b[j-1]){
c=b[j-1];
b[j-1]=b[j];
b[j]=c;
}
}
}
cout<<b[1]<<' '<<b[2]<<' '<<b[3]<<endl;
return 0;
}