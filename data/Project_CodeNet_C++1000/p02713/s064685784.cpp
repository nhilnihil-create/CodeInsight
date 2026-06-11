#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 2; i <= (int)(n); i++)
typedef long long ll;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    ll K;
    cin >> K;
    ll res = 0;
    ll gcd = 0;
    for(int a=1;a<=K;a++){
        for(int b=1;b<=K;b++){
            gcd=GCD(a,b);
            for(int c=1;c<=K;c++){
                res+=GCD(gcd,c);
            }
        }
    }
    cout<<res;
    return 0;
}