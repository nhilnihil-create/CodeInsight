#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long double B){
    long long iB = B * 100 + 0.1;
    A *= iB;
    A /= 100;
    cout << A << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    double B;
    scanf("%lf",&B);
    solve(A, B);
    return 0;
}
