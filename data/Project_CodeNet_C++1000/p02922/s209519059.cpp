#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;

    ll ans = 0, k = 1;
    while(k < B) {
        k += A - 1;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}