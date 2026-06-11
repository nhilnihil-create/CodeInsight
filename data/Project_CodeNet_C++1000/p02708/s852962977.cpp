#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll N , K , a = 0 , mod = 1e9 + 7;
    cin >> N >> K;
    for(ll i = K; N + 1 >= i; i++){
        a = (a + (N - i + 1) * i + 1) % mod;
    }
    cout << a << endl;
}
