#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll N,K; cin >> N >> K;
    ll ans;
    ll x=N/K;
    N -= x*K;
    if(abs(N-K)<N) ans = abs(N-K);
    else ans = N;
    cout << ans << endl;
    return 0;
}