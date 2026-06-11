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
    vector<int>a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a1,b1;
        cin>>a1>>b1;
        a.push_back(a1);
        b.push_back(b1);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2)
        print(b[n/2]-a[n/2]+1);
    else
        print(b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1);
}   