#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 998244353;
const ll INF = 1e16;

int main() {
    FASTIO

    int n;
    cin >> n;
    int total = 0;
    for(int i=1; i<=n; i++) {
        total += n/i;
        if(n%i == 0)
            total--;
    }
    cout << total << "\n";
        
    return 0;
}