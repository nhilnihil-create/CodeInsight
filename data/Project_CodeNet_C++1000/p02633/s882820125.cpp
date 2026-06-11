#include <bits/stdc++.h>
using namespace std;


void solve(long long X){
    cout << 360 / gcd(X, 360) << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
