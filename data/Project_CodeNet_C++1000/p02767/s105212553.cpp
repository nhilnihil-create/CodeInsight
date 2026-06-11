#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int Min = arr[0];
    long long int Max = arr[n-1];
    long long int ans = LLONG_MAX;
    for(long long int i=Min;i<=Max;i++)
    {
        long long temp=0;
        for(int j=0;j<n;j++)
        {
            temp+=abs(arr[j]-i)*abs(arr[j]-i);
        }
        ans=min(ans,temp);
    }
    cout<<ans<<"\n";
}