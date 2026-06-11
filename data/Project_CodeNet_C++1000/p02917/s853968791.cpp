#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n,ans = 0;
    cin>>n;
    int arr [ n -1 ];
    for(int i = 0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    ans = arr[0] + arr[n-2];
    for(int i = 1;i<n-1;i++)
    {
        ans = ans + min(arr[i],arr[i-1]);
    }
    cout<<ans;
    return 0;
}