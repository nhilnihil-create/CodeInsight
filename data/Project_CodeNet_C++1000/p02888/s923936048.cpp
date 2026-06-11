#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> L){
    sort(L.begin(), L.end());
    long long res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
            res += max(k - (j+1), 0);
        }
    }
    cout << res << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> L(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&L[i]);
    }
    solve(N, std::move(L));
    return 0;
}
