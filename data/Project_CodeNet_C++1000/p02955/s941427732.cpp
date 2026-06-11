#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int N;ll K; cin >> N >> K;
    vector<ll> A(N);
    ll s=0;
    ll ans = 0LL;
    REP(i,N){
        cin >> A[i];
        s += A[i];
    }
    vector<ll> v = calc_divisor(s);

    for(ll yaku:v){
        vector<ll> diff;
        REP(i,N) {
            ll r = A[i]%yaku;
            diff.push_back(r);
        }
        sort(all(diff));
        ll cnt = K;
        REP(i,N){
            ll t = min(cnt, diff[i]);
            diff[i] -= t;
            cnt -= t;
        }
        cnt = K;
        for (int i=N-1; i>=0; i--){
            ll t = min(cnt, diff[i]%yaku?yaku-diff[i]:0);
            diff[i] += t;
            cnt -= t;
        }
        bool check = true;
        REP(i,N){
            if (diff[i]%yaku!=0) check = false;
        }
        if(check) ans = yaku;
    }
    cout << ans <<endl;
    return 0;
}