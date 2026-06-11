#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> B){
    ll ans = B[0] + B[N-2];
    for(int i = 0; i < N-2; ++i) ans += min(B[i], B[i+1]);
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> B(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(B));
    return 0;
}
