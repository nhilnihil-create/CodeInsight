#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ld a,b,x,y,area;
    cin>>a>>b>>x>>y;
    area=(a*b)/2;
    ll flag=0;
    if(a/2==x && b/2==y) flag=1;
    cout<<fixed<<setprecision(8)<<area<<" ";
    if(flag==1) cout<<1;
    else cout<<0;
}