#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,i,j,a,b;
    cin>>n;
    long long arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    a=0;
    b=1000;
    for(i=0;i<n;i++)
    {
        if(a==0)
        {
            if(i<n-1&&arr[i]<arr[i+1])
            {
                a=b/arr[i];
                b=b%arr[i];
            }
        }
        else
        {
            if(i==n-1||arr[i]>arr[i+1])
            {
                b=b+(a)*arr[i];
                a=0;
            }
        }
    }
    cout<<b;
}