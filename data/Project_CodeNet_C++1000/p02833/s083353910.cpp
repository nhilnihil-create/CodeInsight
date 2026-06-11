#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
int main()
{
    ll n, ans=0;
    cin >> n;
    if ( n % 2) cout << 0, exit(0);
    for(ll i=5;i<=n;i*=5)
    ans += (n/(2*i));
    cout << ans << endl;

}
