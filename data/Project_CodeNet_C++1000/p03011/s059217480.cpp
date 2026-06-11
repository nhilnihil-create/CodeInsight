#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,q,r;
    cin>>n>>q>>r;
    cout<<(n+q+r-max(max(n,q),r));
    return 0;



}

