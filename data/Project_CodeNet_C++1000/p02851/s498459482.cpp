#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn = 10005;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    ll n, m;
    while (cin >> n >> m) {
        ll ans = 0;
        map<ll,ll>mp;
        vector<ll>pre;
        mp[0] = 1;
        ll sum = 0;
        pre.pb(0);
        f1(n) {
            ll x;
            cin >> x;
            x += m - 1;
            x %= m;
            sum += x;
            sum %= m;
            if (i >= m) {
                mp[pre[i-m]]--;
            }
            ans += mp[sum];
            mp[sum]++;
            pre.pb(sum);
        }
        cout << ans << '\n';
    }
}