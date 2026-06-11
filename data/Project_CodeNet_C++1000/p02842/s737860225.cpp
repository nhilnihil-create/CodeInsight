#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    ll a,b,i,j,n,k;
    cin>>n;
    long double c,d;
    c=n/1.08;
    //cout<<c<<endl;
    c=ceil(c);
    b=(ll)c;
    //cout<<c<<endl;
    c=c*1.08;
    //cout<<c<<endl;
    c=floor(c);
    //cout<<c<<endl;
    if(n==(ll)c) cout<<b;
    else cout<<":(";
}