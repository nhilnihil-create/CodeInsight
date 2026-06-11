#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, r, d;
    cin >> l >> r >> d;

    int ans = 0;
    int init = l / d;
    init = init * d;
    while (init <= r) {
        //cout << init << " ";
        if (init <= r && init >= l) {
            ans ++;
        }
        init += d;
    }
    cout << ans << "\n";
    return 0;
}