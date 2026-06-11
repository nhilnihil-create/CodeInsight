#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,k,j,d,a[200]={0},i,l,h,s=0;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>d;
        for(j=1;j<=d;j++)
        {
            cin>>l;
            a[l]=a[l]+1;
        }
    }
    for(h=1;h<=n;h++)
    {
        if(a[h]==0)
        {
            s++;
        }
    }
    cout<<s<<endl;
    return 0;
}