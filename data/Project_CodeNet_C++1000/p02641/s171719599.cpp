#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int X, N; cin >> X >> N;
    vector<bool> good(110, true);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        good[a] = false;
    }
    
    int a = X-1, b = X+1, res = 0;
    if (good[X]) cout << X << '\n';
    else {    
        while(a > -1 && b <= 105) {
            if (a > -1 && good[a]) {
                res = a;
                break;
            }
            else if (b <= 105 && good[b]) {
                res = b;
                break;
            }
            --a, ++b;
        }
       cout << res << '\n';
    }
}
