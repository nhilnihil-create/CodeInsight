#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> A){
    vector<long long> A2 = A;
    sort(A2.begin(), A2.end(), greater<long long>());
    //for(auto i : A2) cout << i << endl;
    long long max_val = A2[0];
    long long sec_val = A2[1];
    for(auto a : A){
        if(a == max_val) cout << sec_val << endl;
        else cout << max_val << endl;
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
