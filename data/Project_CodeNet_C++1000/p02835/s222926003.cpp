#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(std::vector<long long> A){
    ll sum = 0;
    rep(i,3){
        sum += A[i];
    }
    if(sum >= 22){
        cout << "bust" << endl;
    } else{
        cout << "win" << endl;
    }
}

int main(){
    std::vector<long long> A(3);
    for(int i = 0 ; i < 3 ; i++){
        scanf("%lld",&A[i]);
    }
    solve(std::move(A));
    return 0;
}
