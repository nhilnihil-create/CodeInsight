#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
 ll n,a,b; cin>>n>>a>>b; ll k=(n/(a+b));
 if(n%(a+b)==0){cout<<k*a;}
 else {
    k=k*a; ll m=n%(a+b); m=min(a,m); cout<<k+m;
 }
}


