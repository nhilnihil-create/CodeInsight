#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll buf = C*D/GCD(min(C,D), max(C,D));
    cout << B-A+1-(B/C-(A-1)/C)-(B/D-(A-1)/D)+(B/buf-(A-1)/buf) << endl;
    return 0;
}