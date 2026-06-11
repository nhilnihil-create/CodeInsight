#include<iostream>
using namespace std;
int main()
{
int n,k ,i,j,p[100000],sum=0;
cin>>n>>k;
for(j=0; j<n;j++){cin>>p[j];}

for(i=0; i<n;i++){
    for(j=i+1;j<n;j++){
        if(p[j]<p[i]){
            int temp=p[i];
            p[i]=p[j];
            p[j]=temp;}
    }}
for(i=0;i<k;i++){
    sum=sum+p[i];
}
cout<<sum;
return 0;}