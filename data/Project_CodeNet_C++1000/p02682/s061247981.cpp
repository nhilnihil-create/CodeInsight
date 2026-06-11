#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll A,B,C,K; cin >> A >> B >> C >> K;
    ll a = min(A,K);
    ll b = min(B,K - a);
    ll c = max(K - (a+b), (ll)0);
    cout << a-c << endl;
    return 0;
}