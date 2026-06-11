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
    int arr[n];
    int xorr=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        xorr^=arr[i];
    }
    for(int i=0;i<n;i++)
        cout<<(xorr^arr[i])<<" ";
}   







