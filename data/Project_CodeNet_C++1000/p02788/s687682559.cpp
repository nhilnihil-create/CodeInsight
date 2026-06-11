#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, D, A;
    cin >> N >> D >> A;
    VP X(N); 
    VL XX(N);
    rep(i, 0, N){
        ll x, h;
        cin >> x >> h;
        h = (h+A-1)/A;
        X[i] = {x, h};
        XX[i] = x;
    }
    sort(ALL(X));
    sort(ALL(XX));

    ll ans = 0;
    VL imos(N+1, 0);
    rep(i, 0, N){
        imos[i+1] += imos[i];
        X[i].second += imos[i];
        if(X[i].second <= 0) continue;
        ans += X[i].second;
        if(i == N-1) break;
        auto itr = upper_bound(XX.begin()+i, XX.end(), X[i].first+2*D);
        auto pos = distance(XX.begin(), itr);
        if(pos-1 > i){
            imos[i+1] -= X[i].second;
            imos[pos] += X[i].second;
        }
    }
    
    cout << ans << endl;
    return 0;
}