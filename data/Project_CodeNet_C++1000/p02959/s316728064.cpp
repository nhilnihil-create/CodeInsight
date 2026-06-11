#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N + 1,0);
    vector<ll> a(N + 1,0);
    for(ll i = 0; i < N + 1; i++) {
        cin >> A.at(i);
    }
    vector<ll> B(N,0);
    vector<ll> b(N,0);
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    a = A;
    b = B;
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans += min(A.at(i), B.at(i));
        B.at(i) -= min(A.at(i), B.at(i));
        ans += min(A.at(i + 1), B.at(i));
        A.at(i + 1) -= min(A.at(i + 1), B.at(i));
    }
    
    ll anss = 0;
    A = a;
    B = b;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(ll i = 0; i < N; i++) {
        anss += min(A.at(i), B.at(i));
        B.at(i) -= min(A.at(i), B.at(i));
        anss += min(A.at(i + 1), B.at(i));
        A.at(i + 1) -= min(A.at(i + 1), B.at(i));
    }

    cout << max(ans, anss) << endl;

    return 0;
}