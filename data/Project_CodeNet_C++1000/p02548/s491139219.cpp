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
    ll c=1;
    ll s=0;
    ll x=n;
    while(c<n)
    {
        x=n/c;
        if(n%c==0)
            s=s+x-1;
        else
            s=s+x;
        c++;
    }
    cout<<s<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
