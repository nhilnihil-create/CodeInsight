#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N,K; cin >> N >> K;
    vector<ll> H;
    ll ans = 0;
    for(int i=0; i<N; i++) {
        ll x; cin >> x;
        H.push_back(x);
    }
    sort(H.begin(),H.end(),greater<>());
    for(int i=K; i<N; i++) ans += H[i];
    cout << ans << endl;
}