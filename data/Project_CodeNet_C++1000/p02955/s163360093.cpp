#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

ll n, k;
ll a[500];

bool check(ll div){
    vector<ll> b(n);
    rep(i,n) b[i] = a[i]%div; sort(all(b));
    vector<ll> sum1(n+1,0), sum2(n+1,0);
    rep(i,n) sum1[i+1] = sum1[i] + b[i];
    rrep(i,n) sum2[i] = sum2[i+1] + (div-b[i])%div;
    bool res = false;
    rep(i,n+1) if(sum1[i] <= k && sum2[i] <= k) { res = true; break; }
    return res;
}

int main(){
    cin >> n >> k;
    rep(i,n) cin >> a[i];
    ll sum = 0; rep(i,n) sum += a[i];
    ll ans = 1;
    for(ll i = 1; i*i <= sum; i++){
        if(sum%i == 0){
            if(check(sum/i)) { chmax(ans,sum/i); break; }
            if(check(i)) chmax(ans,i);
        }
    }
    cout << ans << endl;
    return 0;
}