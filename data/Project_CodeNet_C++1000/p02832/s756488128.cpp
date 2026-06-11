#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> a){
    ll cnt = 0;
    ll pos = 1;
    for(ll i = 0; i < N; i++){
        if(pos == a[i]){
            pos++;
        }else{
            cnt++;
        }
    }
    if(cnt == N) cnt = -1;
    cout << cnt << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
