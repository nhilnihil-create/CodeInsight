#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll n, mn = 1e12;
    cin >> n;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ll sec = n/i;
            mn = min(mn, i + sec - 2);
        }
    }
    cout << mn;
    return 0;
}