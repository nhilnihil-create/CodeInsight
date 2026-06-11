#include<iostream>
using namespace std;
long long a[200005],b[200005]={0},c[200005],d[200005];
int main()
{
    long long n,i,j,x,k=1,total=0,z,l,m;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        x=a[i];
        if(b[x]==0)
        {
            c[k]=x;
            k++;
        }
        b[x]=b[x]+1;
    }
    for(j=1;j<k;j++)
    {
        x=c[j];
        d[x]=(b[x]*(b[x]-1))/2;
        total+=d[x];
    }
    for(i=1;i<=n;i++)
    {
        x=a[i];
        z=total-d[x];
        l=b[x]-1;
        m=(l*(l-1))/2;
        cout<<(z+m)<<endl;        
    }
    return 0;    
}