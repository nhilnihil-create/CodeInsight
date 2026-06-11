//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll a,b,c;
    ll x,y,z;
    cin>>a>>b>>c;
    x=c-a-b;
    y=4*a*b;
    bool ok=x>0&&y<x*x;
    if(ok)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}



