#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<double> ans(n+1);
    ll sum = 0;
    rep(i,p[0]){
        sum += i+1;
    }
    ans[0] = 0;
    ans[1] = (double)sum/p[0];
    for(int i = 1;i < n;++i){
        sum = 0;
        rep(j,p[i]){
            sum += j+1;
        }
        ans[i+1] = ans[i] + (double)sum/p[i];
    }
    double res = 0;
    rep(i,n){
        res = max(res,ans[i+k]-ans[i]);
        if(i+k == n) break;
    }

    cout << fixed << setprecision(10) << res << endl;


    cout << endl;
    return 0;
}
