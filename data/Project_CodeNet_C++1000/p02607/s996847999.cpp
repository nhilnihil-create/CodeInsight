#include<iostream>
using namespace std;
int main()
{
    int i,n,a[100],p=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i=i+2)
    {
        if(a[i]%2==1)
        {
            p=p+1;
        }
    }
    cout<<p<<endl;
    return 0;
}
