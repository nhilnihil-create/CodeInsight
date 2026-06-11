#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < N; i++)
#define rep2(i, x, n) for (int i = x; i < N; i++)
using ll = long long int;
int main() {
    int N=0;
    ll D=0;
    cin >> N >> D;
    D *= D;
    vector<ll> X(N);
    vector<ll> Y(N);
    int ans=0;
    rep(i, n) {
        cin >> X.at(i) >> Y.at(i);
        X.at(i) *= X.at(i);
        Y.at(i) *= Y.at(i);
        if (X.at(i) + Y.at(i) <= D) ans++;
    }
    cout << ans << endl;
    return 0;
}