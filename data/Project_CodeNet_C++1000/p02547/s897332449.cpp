#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
const ll maxn=(3*1e3)+5;
const int N = 1e5;
int main()
{
    ll n;
    cin>>n;
    ll a[n][2],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    int f=0;
    for(i=0;i<n-2;i++)
    {
        if(a[i][0]==a[i][1] && a[i+1][0]==a[i+1][1] && a[i+2][0]==a[i+2][1])
            f=1;
    }
    if(f)
        cout<<"Yes"<<"\n";
    else
        cout<<"No"<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
