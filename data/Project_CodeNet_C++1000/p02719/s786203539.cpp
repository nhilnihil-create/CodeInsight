//IN THE NAME OF "ALLAH".......
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n , k ;
    cin>>n>>k;
    ll ans = n%k ;
    ll value = min(ans, abs(ans-k));
    cout<< value <<endl;
}
