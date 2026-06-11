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
    ll a,b,i,j,n,t,c;
    cin>>n>>a;
    a*=2;
    a++;
    b=n%a;
    n/=a;
    if(b>0) n++;
    cout<<n;
}