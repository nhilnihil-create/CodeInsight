#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    sum+=arr[0];sum+=arr[n-2];
    for(int i=0;i<n-2;i++)
    {
        sum+=min(arr[i],arr[i+1]);
    }

    cout<<sum<<endl;

}
