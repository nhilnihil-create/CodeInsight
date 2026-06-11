#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,c=0;
    cin>>n;
    ll a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            c++;
        }
    }
    if(c<=2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}
