#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll q = n/k;
    ll temp = k*( q+1);
    ll ans = min( abs( temp - n) , n%k  );
    cout<<ans;
}