#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    long long int ans=1000;
    long long int counter=1000;
    long long int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            counter=ans/a[i];
            ans-=(counter)*a[i];
            ans+=counter*a[i+1];
        }

    }

    cout<<ans;

}
