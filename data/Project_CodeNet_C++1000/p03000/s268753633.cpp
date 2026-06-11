#include <iostream>
using namespace std;

int solve() {
    int n, x; cin >> n >> x;
    int d{0}, l;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        d += l;
        if (d <= x) {
            res++;
        } else {
            break;
        }
    }
    
    return res;
}

int main() {
    cout << solve() << endl;
}