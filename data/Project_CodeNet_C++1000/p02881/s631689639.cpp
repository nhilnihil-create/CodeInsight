#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll tm=n;
    for(ll i=sqrt(n);i>0;i--)
    {
        if(n%i==0)
        {
            tm=i;
            break;
        }
    }
    ll tm2= n/tm;
    cout<< tm+tm2-2;
}
