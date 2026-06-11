#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    ll a,b,i,j,n,k;
    ll m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    if(m1==2)
    {
        if(d1==28) cout<<"1";
        else cout<<"0";
    }
    else if(m1<=7)
    {
        if(m1%2 && d1==31) cout<<"1";
        else if(m1%2==0 && d1==30) cout<<"1";
        else cout<<"0";
    }
    else
    {
        if(m1%2 && d1==30) cout<<"1";
        else if(m1%2==0 && d1==31) cout<<"1";
        else cout<<"0";
    }
}