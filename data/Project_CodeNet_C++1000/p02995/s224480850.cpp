#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (a%b==0) return b;
    else return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
    return a*b / gcd(a,b);
}

int main() {
    long long A, B, C, D, c, d, cd;
    cin >> A >> B >> C >> D;
    c = (B/C) - (A-1)/C; // Cで割り切れるA以上B以下の数の個数
    d = (B/D) - (A-1)/D; // Dで割り切れるA以上B以下の数の個数
    cd = (B/lcm(C,D)) - (A-1)/lcm(C,D);
    cout << (B-A+1) - c - d + cd << endl;
}