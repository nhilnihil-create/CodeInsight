#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin>>x;
    ll y=x;
    ll a=360;
    ll rotate=0;
    while(x%a!=0)
    {
        x+=y;
        rotate++;
    }
    cout<<rotate+1<<"\n";
}