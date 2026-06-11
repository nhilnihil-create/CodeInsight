#include<iostream>
using namespace std;
int main()
{
    long long n,b[200005]={0},i,x,j;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x;
        b[x]=b[x]+1;
    }
    for(j=1;j<=n;j++)
    {
        cout<<b[j]<<endl;
    }
    return 0;
}