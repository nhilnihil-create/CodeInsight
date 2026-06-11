#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M, std::vector<long long> A){
    priority_queue<long long> que;
    for(auto a: A) que.push(a);
    for(int i = 0; i < M; ++i){
        long long max_val = que.top();
        que.pop();
        que.push(max_val/2);
    }
    long long ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, M, std::move(A));
    return 0;
}
