#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double


// EDITORIAL HELP
// NUMBER of connected comp = No of nodes - no of edges
int32_t main() 
{
    IOS;
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=i*(n-i+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        ans-=a*(n-b+1);
    }
    print(ans);
}   