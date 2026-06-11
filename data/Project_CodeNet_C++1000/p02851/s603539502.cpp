#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    ll a[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    ll s[200005];
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i - 1]) % k;
    map<ll, ll> mp;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if(i >= k) mp[s[i - k]]--;
        ans += mp[s[i]];
        mp[s[i]]++;
    }
    cout << ans << endl;
}
