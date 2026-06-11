#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    bool f = false;
    while(a>0 && c>0)
    {
        if(!f)
        {
            c -= b;
            f = true;
        }
        else
        {
            a -= d;
            f = false;
        }  
    }
    if(a<=0 && c>0)
    {
        cout<<"No"<<'\n';
    }
    else
    {
        cout<<"Yes"<<'\n';
    }
}
    