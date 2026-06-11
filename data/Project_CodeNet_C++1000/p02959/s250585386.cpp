#include<iostream>
using namespace std;
int main()
{
    long long n,i,s=0;
    cin>>n;
    long long a[n+1];
    long long b[n];
    for(i=0;i<n+1;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        if(b[i]<a[i])
        {
            s=s+b[i];
        }
        else
        {
            s=s+a[i];
            b[i]=b[i]-a[i];
            if(b[i]<a[i+1])
            {
                s=s+b[i];
                a[i+1]=a[i+1]-b[i];
            }
            else
            {
                s=s+a[i+1];
                a[i+1]=0;
            }

        }
    }
    cout<<s<<endl;
    return 0;
}
