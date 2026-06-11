#include <bits/stdc++.h>          
using namespace std;             
typedef long long ll;  

int main() {
    ll K;
    cin >> K;
    ll ans = -1;
    queue<ll> que;
    que.push(7);

    for (ll i=0; i<K; i++) {
        ll a = que.front();
        if (a%K == 0) {
            ans = i+1;
            break;
        }
        que.push((a*10+7)%K);
        que.pop();
    }
    cout << ans << endl;
}