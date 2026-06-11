#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int k; cin >> k;
    queue<ll> que;
    for(int i=1; i<10; i++) que.push(i);
    for(int i=0; i<k-1; i++) {
        ll n = que.front();
        que.pop();
        for(int j=-1; j<2; j++) {
            ll m = (n % 10) + j;
            if(m >= 0 && m <= 9) {
                que.push(n * 10 + m);
            }
        }
    }
    cout << que.front() << endl;
}