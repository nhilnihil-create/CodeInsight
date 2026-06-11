#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    ll ans = 0;
    ll max_number = 1e7;
    vector<ll> era(max_number+1, 2);
    era[0] = 1;  era[1] = 1;
    for(i = 2;i <= max_number;++i){
        for(j = 2*i;j <= max_number;j += i){
            ++era[j];
        }
    }
    for(i = 1;i <= n;++i){
        ans += i*era[i];   
    }
    cout << ans << endl;

    return 0;
}
