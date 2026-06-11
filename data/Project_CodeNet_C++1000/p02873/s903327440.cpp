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
    string s;
    cin >> s;
    ll ans=0,n=s.size();
    vector<ll> a(n+1,0);
    rep(i,n){
        if(s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);
    }
    for(int i=n-1; i>=0; i--){
        if(s[i] == '>') a[i] = max(a[i], a[i+1]+1);
    }
    rep(i,n+1) ans += a[i];
    cout << ans << endl;
    return 0;
}