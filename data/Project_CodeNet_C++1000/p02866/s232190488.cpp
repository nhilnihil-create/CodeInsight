#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;

int main() {
    int n; cin >> n;
    int d; cin >> d;
    if (d != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> dist(n);
    dist[0] = 1;
    for (int i=0; i<n-1; ++i) {
        cin >> d;
        dist[d]++;
    }
    if (dist[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    for (int i=1; i<n-1; ++i) {
        if (dist[i] == 0 && dist[i+1] != 0) ans = 0;
        else {
            for (int j=0; j<dist[i+1]; ++j) {
                ans *= dist[i];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
}