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

vector<ll> yakusu(ll n){
    vector<ll> ret;
    for(ll i = 1; i*i <= n; i++){
        if(n % i != 0) continue;
        ret.push_back(i);
        if(i*i != n) ret.push_back(n/i);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    ll N, K;
    cin >> N >> K;
    VL A(N);
    rep(i, 0, N) cin >> A[i];
    ll sum = accumulate(ALL(A), 0);
    auto d = yakusu(sum);
    reverse(ALL(d));
    rep(i, 0, d.size()){
        VL r(N);
        rep(j, 0, N) r[j] = A[j]%d[i];
        sort(ALL(r));
        VL L(N+1, 0), R(N+1, 0);
        rep(j, 0, N) L[j+1] = L[j] + r[j];
        for(ll j = N-1; j >= 0; j--) R[j] = R[j+1] + (d[i] - r[j]);
        rep(j, 0, N+1){
            if(L[j] == R[j] && L[j] <= K){
                cout << d[i] << endl;
                return 0;
            }
        } 
    }
    return 0;
}