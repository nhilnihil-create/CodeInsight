#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> A){
    map<long long, long long> mp;
    for(int i = 0; i < N; ++i) mp[A[i]] += 1;
    long long res = 0;
    for(auto itr : mp) res += itr.second * (itr.second - 1) / 2;
    for(int i = 0; i < N; ++i){
        long long n = mp[A[i]];
        long long before = n * (n-1)/2;
        long long after = (n-1) * (n-2)/2;
        cout << res - before + after << endl;
    }
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
