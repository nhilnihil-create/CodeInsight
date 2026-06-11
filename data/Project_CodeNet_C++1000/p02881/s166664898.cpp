#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    ll x=1, y;
    for(ll i=1; i*i<=N; i++) {
        if (N % i == 0) {
            x = i;
            y = N / i;
        }
    }
    cout << (x-1) + (y-1) << endl;
}