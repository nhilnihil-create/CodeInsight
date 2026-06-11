#include<iostream>
using namespace std;
int main()
{
    long long n,m,i,a[200000],total=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a[i];
        total+=a[i];
    }  
    if(total>n)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<(n-total)<<endl;
    }
    return 0;
}