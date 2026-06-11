#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long M){
    cout << (N * (N-1))/2 + (M * (M-1))/2 << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    solve(N, M);
    return 0;
}
