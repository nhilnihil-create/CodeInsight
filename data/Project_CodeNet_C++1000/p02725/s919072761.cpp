#include<iostream>
using namespace std;

int main()
{
    int k,n;cin>>k>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int mx=0;
    for(int i=0;i<n;i++){
    if(i==n-1)
    mx=max(mx,k-arr[i]+arr[0]);
    else mx=max(mx,arr[i+1]-arr[i]);
    }
    cout<<k-mx<<endl;
    return 0;
}