#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll n;cin>>n;
    string s;cin>>s;
    if(n%2==1)
        cout<<"No";
    else
    {
        if(s.substr(0,n/2)==s.substr(n/2))
            cout<<"Yes";
        else
            cout<<"No";
    }
}

    
