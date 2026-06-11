#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, d, a, ans = 0;
    cin >> n >> d >> a;
    vector<P> x(n);
    rep(i, n)cin >> x[i].first >> x[i].second;
    sort(all(x)); 
    vector<int> sum(n,0), b(n);
    rep(i, n)b[i] = x[i].first;
    rep(i, n){
        if(i)sum[i] += sum[i-1];
        int h = x[i].second, now = x[i].first;
        h -= sum[i] * a;
        if(h <= 0)continue;
        else{
            auto it = upper_bound(all(b), now+2*d);
            sum[i] += (h+a-1)/a;
            ans += (h+a-1)/a;
            if(it != b.end())sum[it-b.begin()] -= (h+a-1)/a;
        }
    }
    cout << ans << endl;
}
