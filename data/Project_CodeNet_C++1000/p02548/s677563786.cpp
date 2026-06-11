#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin>>n;

    ll i,j,tot=0;
    for(i=1;i<n;i++)
    {
        for(j=1;j*i<n;j++)
            tot++;
    }
    cout<<tot;
    return 0;
}
