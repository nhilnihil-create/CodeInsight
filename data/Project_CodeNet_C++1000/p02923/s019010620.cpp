#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n, ans=0,tmp=0;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    rep(i,n-1){
        if(h[i] >= h[i+1]) tmp++;
        else tmp = 0;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}