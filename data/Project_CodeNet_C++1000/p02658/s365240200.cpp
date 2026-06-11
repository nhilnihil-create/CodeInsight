#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, ans=1;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    bool out=false;
    rep(i,n){
        if(ans > INF/a[i]) out = true;
        else ans *= a[i];
    }
    if(out) ans = -1;
    cout << ans << endl;
    return 0;
}