#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define setpres(x) fixed<<setprecision(x)
using namespace std;
bool isprime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int32_t main()
{
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cout<<"ACL";
    }
}

