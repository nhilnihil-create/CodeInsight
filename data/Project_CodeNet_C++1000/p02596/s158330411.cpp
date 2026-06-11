#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll K;

int main() {
    cin >> K;

    ll repsept[1000010];
    memset(repsept, 0, sizeof(repsept));
    repsept[1] = 7 % K;
    for (ll i = 2; i < 1000010; i++) {
        repsept[i] = ((10 * repsept[i-1] % K) + 7) % K;
    }

    int ans = -1;
    for (int i = 1; i < 1000010; i++) {
        if (repsept[i] == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    
    return 0; 
}