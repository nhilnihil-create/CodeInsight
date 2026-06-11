#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    ll S = 0;
    for (int i=0; i<m; i++) {
        int ai;
        cin >> ai;
        S += ai;
    }
    if (S > n) cout << -1 << endl;
    else cout << (n - S) << endl;
}