//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,a,b,c,x,y,z;
    cin>>a>>b>>c;
    x=a+b;
    y=b+c;
    z=c+a;
        cout<<min(x,min(y,z))<<endl;




    return 0;
}



