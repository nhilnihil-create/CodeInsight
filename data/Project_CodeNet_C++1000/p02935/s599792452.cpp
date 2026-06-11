#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll arr[n+5]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    double avg=arr[0]+arr[1];
    avg/=2;
    for(int i=2;i<n;i++)
    {
        avg+=arr[i];
        avg/=2;
    }
    cout<<avg<<endl;
}
