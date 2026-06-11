#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

const int MOD = 2019;


int main() {
    int l, r, res = MOD;
    
    cin >> l >> r;
    
    for(int i = 0; i < 2 * MOD && l + i <= r; i++) {
        for(int j = 0; j < 2 * MOD && l + j <= r; j++) {
            int x = l + i;
            int y = l + j;
            if(x != y) {
                res = min(res, ((x % MOD) * (y % MOD)) % MOD);
            }
        }
    }

    cout << res;
    
    return 0;
}