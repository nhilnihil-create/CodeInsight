#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long K, long long Q, std::vector<long long> A){
    vector<long long> cnt_win(N, 0);
    for(auto a : A){
        cnt_win[a-1] += 1;
    }
    for(auto cnt : cnt_win){
        if(K - (Q - cnt) > 0) cout << YES << endl;
        else cout << NO << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, Q, std::move(A));
    return 0;
}
