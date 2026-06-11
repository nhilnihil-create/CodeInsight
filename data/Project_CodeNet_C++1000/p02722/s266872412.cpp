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
    set<int>s;
    int ans=0;
    for(int i=1;i*i<=(n-1);i++)
    {
        if((n-1)%i==0)
        {
            s.insert((n-1)/i);
            s.insert(i);
        }
    }
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            s.insert(n/i);
            s.insert(i);
        }
    }
    for(int i:s)
    {
        if(i==1)
            continue;
        int temp=n;
        while(temp%i==0)
            temp/=i;
        int mul=temp/i;
        temp-=mul*i;
        if(temp==1)
            ans++;
    }
    print(ans);
}   
