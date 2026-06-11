#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll K;
    cin >> K;
    queue<ll> que;
    for (int i=1; i<=9; i++) {
        que.push(i);
    }

    ll x;
    for (ll i=0; i<K; i++) {
        x = que.front();

        if (x%10 != 0) {
            que.push(10*x + (x%10-1));
        }

            que.push(10*x + (x%10));

        if (x%10 != 9) {
            que.push(10*x + (x%10+1));
        }

        que.pop();
    }

    cout << x << endl;
}