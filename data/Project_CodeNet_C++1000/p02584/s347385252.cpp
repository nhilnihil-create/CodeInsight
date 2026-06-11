#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,a,c,d,l,r;
    cin>>a>>b>>c;
    a=abs(a);
    x=min(a/c,b);
    b-=x;
    a-=x*c;
    if(b & 1)
        cout<<c-a<<'\n';
    else
        cout<<a<<'\n';
}







