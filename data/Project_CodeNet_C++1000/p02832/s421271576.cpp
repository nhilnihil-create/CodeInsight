#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long a[200005],i,n,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[0]=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]-a[i-1]!=1)
        {
            s++;
            a[i]=a[i-1];
        }
    }
    if(s==n)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<s<<endl;
    }
    return 0;
}