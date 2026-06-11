#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){ return b ? gcd(b,a%b) : a; }
long long lcm(long long a, long long b){ return a/gcd(a,b)*b; }

void solve(long long A, long long B){
    cout << lcm(A, B) << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
