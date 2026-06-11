#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a,b,n;
int main()
{
    cin>>a>>b>>n;
    ll x= min(b-1,n);
    cout<<a*x/b<<endl;
    return 0;
}