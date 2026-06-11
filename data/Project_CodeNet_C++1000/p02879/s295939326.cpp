#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B){
    if((A >= 1 && A <= 9) && (B >= 1 && B <= 9)) cout << A * B << endl;
    else cout << -1 << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
