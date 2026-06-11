#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

vector<long long> divisor(long long n){
    vector<long long> res;
    for(int i = 1; (long long)i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(begin(res), end(res));
    return res;
}

signed main(){
    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    ll sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> div = divisor(sum);
    reverse(ALL(div));
    for(auto d : div){
        vector<ll> b;
        REP(i,n){
            if(a[i] % d == 0) continue;
            b.emplace_back(a[i] % d);
        }
        int m = b.size();
        sort(ALL(b));
        vector<ll> rb(m);
        REP(i,m){
            rb[i] = d - b[i];
        }
        ll sum[m + 1] = {}, rsum[m + 1] = {};
        REP(i,m){
            sum[i + 1] = sum[i] + b[i];
        }
        for(int i = m - 1; i >= 0; i--){
            rsum[i] = rsum[i + 1] + rb[i];
        }
        ll t = LINF;
        for(int i = 0; i <= m; i++){
            t = min(t, max(sum[i], rsum[i]));
        }
        if(t <= k){
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}