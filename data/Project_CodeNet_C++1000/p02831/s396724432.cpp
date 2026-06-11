#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;
    for(int i = 1; i <= b; i++) {
        if((a * i) % b == 0) {
            cout << a * i << "\n";
            break;
        }
    }
    return 0;
}
