#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll N,M; cin >> N >> M;
    ll sum = 0;
    rep(i,M) {
        ll a; cin >> a;
        sum += a;
    }
    if(N-sum<0) cout << -1 << endl;
    else cout << N-sum << endl;
}