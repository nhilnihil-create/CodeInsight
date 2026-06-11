#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll a,b,i; cin>>a>>b;
    for(i=1;i<=1001;i++)
    {
        if (i*8/100==a&&i/10==b) {cout<<i; return 0;}
    }
    cout<<-1;
	return 0;
}