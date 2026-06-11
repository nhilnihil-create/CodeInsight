#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define pb push_back
#define mk make_pair
#define ull unsigned long long
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    fastIO;
    ll m,d,m1,d1;
    cin>>m>>d>>m1>>d1;
    ll val;
    if(m+1==m1)
    {
        if(d1==1)
        {
            cout<<1<<'\n';
        }
        else
        {
            cout<<0<<'\n';
        }
    }
    else
    {
        cout<<0<<'\n';
    }
    return 0;
}