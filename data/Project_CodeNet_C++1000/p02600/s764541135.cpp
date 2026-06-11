#include <bits/stdc++.h>
#define ll long long
#define ch char
#define st string
using namespace std;
ll a,b,c,d,e,f,g,h;
void Urvatullo_Atoev()
{
    cin>>a;
    if(a>=400 && a<=599)
    {
        cout<<8;
    }
    else if(a>=600 && a<=799)
    {
        cout<<7;
    }
    else if(a>=800 && a<=999)
    {
        cout<<6;
    }
    else if(a>=1000 && a<=1199)
    {
        cout<<5;
    }
    else if(a>=1200 && a<=1399)
    {
        cout<<4;
    }
    else if(a>=1400 && a<=1599)
    {
        cout<<3;
    }
    else if(a>=1600 && a<=1799)
    {
        cout<<2;
    }
    else
    {
        cout<<1;
    }
}
int main()
{
    Urvatullo_Atoev();
}
