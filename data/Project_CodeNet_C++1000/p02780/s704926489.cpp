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
    ll n, k;
    cin >> n >> k;
    vector<double> s(n+1,0);
    double ans = 0;
    rep(i,n){
        ll p;
        cin >> p;
        s[i+1] = s[i] + (p+1)/2.0;
    }
    for(int i=k; i<=n; i++){
        ans = max(ans, s[i] - s[i-k]);
    }
    printf("%f\n",ans);
    return 0;
}