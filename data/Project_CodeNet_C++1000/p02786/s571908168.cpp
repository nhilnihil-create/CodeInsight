#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int64_t H;
    cin >> H;

    int64_t ans=1;
    while(H > 0){
        H /= 2;
        ans *= 2;
    }

    cout << ans-1 << endl;
}
