#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B, long long N){
    long long x = min(N, B-1);
    cout << ((A*x)/B) - 5*(x/B) << endl;
    return;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long N;
    scanf("%lld",&N);
    solve(A, B, N);
    return 0;
}
