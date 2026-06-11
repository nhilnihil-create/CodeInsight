#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],ar[n],a,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    for(int i=1;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]==arr[i]+1)
            sum+=ar[arr[i]];
    }
    cout<<sum<<endl;

}
