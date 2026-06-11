#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N=1e9+7;
int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            ans=ans+abs(arr[i]-arr[i-1]);
            arr[i]=arr[i-1];
        }
    }
    cout<<ans;
}