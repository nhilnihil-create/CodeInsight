#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main(){
    int K;
    cin >> K;
    ll count = 0;

    for(int i=1; i<=K; i++) {
        for(int j=1; j<=K; j++) {
            for(int k=1; k<=K; k++) {
                count += gcd(i, gcd(j, k));
            }
        }
    }
    cout << count << endl;
}