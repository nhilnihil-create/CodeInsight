#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    double ans = (arr[0]+arr[1])/2;
    for(int i=2;i<n;i++)
    {
        ans = (ans+arr[i])/2;
    }
    cout<<fixed<<ans<<"\n";

}