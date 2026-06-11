#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(long long N){
    ll ret = numeric_limits<ll>::max();
    for(ll i=1; i*i<=N; ++i){
        if(N%i==0){
            ll tmp = N/i + i - 2;
            if(tmp<ret) ret = tmp;
        }
    }
    cout << ret << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
