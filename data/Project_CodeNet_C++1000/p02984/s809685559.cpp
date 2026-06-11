#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin>>n;
    vector<ll> a(n);
    for (int i=0; i<n; i++)cin>>a[i];
    ll sum = 0;
    for (int i=0; i<n; i++){
        if (i&1)sum -= a[i];
        else sum += a[i];
    }
    vector<ll> res(n);
    res[0] = sum/2;
    for (int i=1; i<n; i++)res[i] = a[i-1] - res[i-1];
    for (int i=0; i<n; i++)res[i] *= 2;
    for (int i=0; i<n; i++)cout<<res[i]<<" ";
}