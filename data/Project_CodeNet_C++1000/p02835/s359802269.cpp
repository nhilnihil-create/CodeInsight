#include <bits/stdc++.h>
using namespace std;


void solve(std::vector<long long> A){
    if(accumulate(A.begin(), A.end(), 0LL) >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
}

int main(){
    std::vector<long long> A(3);
    for(int i = 0 ; i < 3 ; i++){
        scanf("%lld",&A[i]);
    }
    solve(std::move(A));
    return 0;
}
