#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B, long long K){
    if(A > K){
        A = A - K;
    }else{
        if(B > K - A){
            B = B - (K - A);
        }else{
            B = 0;
        }
        A = 0;
    }
    cout << A << " " << B << endl;
    return;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long K;
    scanf("%lld",&K);
    solve(A, B, K);
    return 0;
}
