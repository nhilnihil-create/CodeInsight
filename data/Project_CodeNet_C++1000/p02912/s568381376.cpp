#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    ll A;
    priority_queue<ll, vector<ll>, less<int>> price;
    rep(i,N) {
        cin >> A;
        price.push(A);
    }
    ll ans = 0;
    rep(i,M) {
        ll discount = price.top() / 2;
        price.pop();
        price.push(discount);
    }
    rep(i,N) {
        ans += price.top();
        price.pop();
    }
    cout << ans << endl;
}
