#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+5],frr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i]>>frr[i];
    bool tr=false;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==frr[i]&&arr[i-1]==frr[i-1]&&arr[i+1]==frr[i+1])tr=true;
    }
    if(tr)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
