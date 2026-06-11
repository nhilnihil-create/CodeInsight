#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> A){
    map<long long, long long> subordinate;
    for(int i = 1; i <= N; ++i) subordinate[i] = 0;
    for(int i = 0; i < N-1; ++i){
        subordinate[A[i]] += 1;
    }
    for(auto i = subordinate.begin(); i != subordinate.end(); ++i){
        cout << i->second << endl;
    }
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N-2+1);
    for(int i = 0 ; i < N-2+1 ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
