#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B){
    if((A - 2 * B) <= 0) cout << 0 << endl;
    else cout << A - 2 * B << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
