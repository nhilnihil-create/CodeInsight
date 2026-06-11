#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n+1]={0};
int i,j,k,sum;
for(i=1;i*i<=n;i++)
{
for(j=1;j*j<=n;j++)
{
for(k=1;k*k<=n;k++)
{
sum=i*i+j*j+k*k+i*j+j*k+k*i;
if(sum<=n)
a[sum]++;
}
}
}
for(i=1;i<=n;i++)
{
cout<<a[i]<<endl;

}
}
