//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int arr[2*n+10]={};
    int sum[2*n+10]={};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i%2)
            sum[i]=sum[i-1]+arr[i];
        else
            sum[i]=sum[i-1]-arr[i];
    }
    cout<<sum[n];
    for(int i=n+1;i<2*n;i++)
    {
        cout<<" ";
        arr[i]=arr[i-n];
        if(i%2)
            sum[i]=sum[i-1]+arr[i];
        else
            sum[i]=sum[i-1]-arr[i];
        if(i%2)
            cout<<(sum[i]-sum[i-n]);
        else
            cout<<(-sum[i]+sum[i-n]);
    }
}
