#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll M = 1000000007;
ll bigm(ll m, ll n)
{
    ll r = 1;
    for(int i=0; i<n; i++)
    {
       r = r*m%M;
    }
    return r;
}
int main(){

    ll n; cin >> n;
    ll ans = bigm(10,n)-bigm(9,n)-bigm(9,n)+bigm(8,n);
    ans%=M;
    ans = (ans+M)%M;
    cout << ans << endl;
    return 0;

}
