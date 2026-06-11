#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,i,l,m=1e13; cin>>n;
    for(i=1;i<=sqrt(n);i++)
    {
        if (n%i==0)
        { 
            l=(n/i)-1+(i-1);
            m=min(m,l);
        }
    }
    cout<<m;
	return 0;
}