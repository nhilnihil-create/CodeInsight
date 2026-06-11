#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int mod = 998244353;

int main() {
    long long N, ans;
    cin >> N;
    long long D[N];
    map<int, int> count;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        count[D[i]]++;
    }
    if (count[0] != 1) {
        ans = 0;
    } else {
        ans = 1;
        for (int i = 1; i < N; i++) {
            ans = (ans * count[D[i] - 1]) % mod;
        }
    }

    cout << ans << "\n";
    return 0;
}
