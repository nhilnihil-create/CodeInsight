#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    if (a%b==0) return b;
    return gcd (b,a%b);

}

int main() {
    int k,d;
    ll sol=0;
    cin >> k;
    for (int a=1;a<=k;a++) {
        for (int b=1;b<=k;b++) {
            for (int c=1;c<=k;c++) {
                d=gcd(max(a,b),min(a,b));
                sol+=gcd(max(d,c),min(d,c));
            }
        }
    }
    cout << sol;

}

