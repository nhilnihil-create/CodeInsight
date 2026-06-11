#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll a,b,i,j,n,m,k,t;
    cin>>n;
    if(n==1) cout<<"1.0000000";
    else if(n%2)
    {
        long double x,y;
        x=(n/2)+1;
        x/=n;
        cout<<setprecision(8)<<fixed<<x;
        
    }
    else cout<<"0.5000000";
}