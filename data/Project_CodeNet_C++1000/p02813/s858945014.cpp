#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll fact(ll n)
{
    if (n==1) {return 1;}
    return n*fact(n-1);
}

int main() {
    ll n,i,p,q,l; vector<ll>a,b,c; cin>>n;
    for(i=0;i<n;i++) {cin>>l; a.pb(l);c.pb(i+1);}
    for(i=0;i<n;i++) {cin>>l; b.pb(l);}
    l=fact(n);
    for(i=0;i<l;i++)
    {
        if (a==c) {p=i;}
        if (b==c) {q=i;}
        next_permutation(c.begin(),c.end());
    }
    cout<<abs(p-q);
	return 0;
}