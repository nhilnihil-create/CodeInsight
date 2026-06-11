#include<iostream>
using namespace std;
long long int k[21][101],n,num[100],sum;
main(){
cin>>n;
for(int i=0;i<n;i++){cin>>num[i];}
k[num[0]][0]=1;
for(int i=1;i<n-1;i++){for(int j=0;j<21;j++){
if(j+num[i]<21){k[j+num[i]][i]+=k[j][i-1];}
if(j-num[i]>=0){k[j-num[i]][i] += k[j][i-1];}
}}
sum=k[num[n-1]][n-2];
cout<<sum<<endl;}