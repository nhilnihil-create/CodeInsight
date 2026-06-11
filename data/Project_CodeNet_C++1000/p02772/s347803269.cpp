#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> A){
    bool check = true;
    for(ll i = 0; i < N; ++i){
        if(A[i] % 2 == 0){
            if(A[i] % 3 == 0 || A[i] % 5 == 0) continue;
            else{
                check = false;
                break;
            }
        }
    }
    if(check) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
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
