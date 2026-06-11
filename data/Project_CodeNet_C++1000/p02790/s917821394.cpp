#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a, b;
    cin>>a>>b;
    if(min(a,b) == a)
    {
        for(ll i=0; i<b; i++)
        {
            cout<<a;
        }
        cout<<endl;
    }
    else
    {
        for(ll i=0; i<a; i++)
        {
            cout<<b;
        }
        cout<<endl;
    }
    return 0;
}
