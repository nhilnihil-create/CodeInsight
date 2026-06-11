#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll fn(ll a)
{
    if (a!=2&&a%2==0) {return 0;}
    for(ll i=3;i<=sqrt(a);i+=2)
    {
        if (a%i==0) {return 0;}
    }
    return 1;
}

int main() {
    ll p,n,i,l; cin>>n;
    if (n==2) {cout<<n; return 0;}
    if (n%2==0) {n++;}
    for(i=n;i<=n*n;i+=2)
    {
        if (fn(i)==1) {cout<<i; return 0;}
    }
	return 0;
}