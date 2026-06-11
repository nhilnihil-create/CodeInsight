#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    ll x=1LL*n*m;
    if(n==1 || m==1)
    {
        cout<<"1"<<endl;
    }
    else if(x%2==0)
    {
        cout<<x/2<<"\n";
    }
    else
    {
        cout<<(x/2)+1<<"\n";
    }
}
