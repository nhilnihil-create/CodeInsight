#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,m,i,j,k,x,y,z;
    cin>>a>>b>>m;
    int ar1[100000],ar2[100000];
    for(i=0;i<a;i++)
        cin>>ar1[i];
    for(j=0;j<b;j++)
        cin>>ar2[j];
   long long int min1=INT_MAX;
    for(i=0;i<a;i++)
    {
        if(ar1[i]<min1)
            min1=ar1[i];
    }
    long long int min2=INT_MAX;
    for(j=0;j<b;j++)
    {
        if(ar2[j]<min2)
            min2=ar2[j];
    }
    long long int sum[100000];
    long long int min3=min1+min2;
    for(k=0;k<m;k++)
    {
        cin>>x>>y>>z;
        sum[k]=ar1[x-1]+ar2[y-1]-z;
        if(min3>sum[k])
            min3=sum[k];
    }
    cout<<min3<<endl;
}
