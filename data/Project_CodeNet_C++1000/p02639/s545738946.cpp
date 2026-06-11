#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int x[5];
    rep(i, 5) cin >> x[i];
    int ans;
    rep(i, 5) {
        if (x[i] == 0) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}