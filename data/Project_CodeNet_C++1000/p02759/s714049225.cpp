#include <bits/stdc++.h>
using namespace std;


void solve(long long N){
    if(N % 2 == 0) cout << N/2 << endl;
    else cout << N/2 + 1 << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
