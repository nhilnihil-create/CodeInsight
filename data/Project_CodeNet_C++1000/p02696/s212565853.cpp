//Radhe Radhe
#include<bits/stdc++.h>//157B
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll i,j,a,b,n,x,y,z;
    cin>>a>>b>>n;
    x=min(b-1,n);
    y=(a*x)/b;
    z=a*(x/b);
    cout<<y-z<<endl;
    return 0;
}



