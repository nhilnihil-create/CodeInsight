#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    cout<<(a*min(n, b - 1)/b)<<'\n';
}