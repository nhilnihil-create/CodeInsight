#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)

void solve(long long N){
    vector<pair<ll, ll>> res;
    for(int i=2; i<=N/i; i++){
        ll b = 0;
        while(N % i == 0){
            N /= i;
            b++;
        }
        res.emplace_back(i,b);
    }
    if(N != 1) res.emplace_back(N,1);

    ll ans = 0;
    for(auto s : res){
        ll p = s.second;
        ll b = 1;
        while (b <= p){
            p -= b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
}


int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
