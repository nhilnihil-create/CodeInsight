#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long X, long long N, std::vector<long long> p){
    ll ans = 0;
    ll score = 999999999999999;
    vector<ll> a(200);
    rep(i,N) a[p[i]] = 1;
    if(N == 0){
        cout << X << endl;
        return;
    }

    for(int i = 0; i<200; i++){
        if(a[i]) continue;
        ll now = abs(i-X);
        if(now < score){
            score = now;
            ans = i;
        }
    }
    cout << ans << endl;

}

int main(){
    long long X;
    scanf("%lld",&X);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    solve(X, N, std::move(p));
    return 0;
}
