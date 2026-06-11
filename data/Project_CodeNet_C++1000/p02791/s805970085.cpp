#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n;
    cin>>n;
    long long a[n],i,k=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long p=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<=p)
        {
            k++;
        p=a[i];
        }
    }
    cout<<k<<endl;

    return 0;
}
