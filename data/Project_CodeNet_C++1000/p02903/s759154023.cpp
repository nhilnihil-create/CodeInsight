#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W, A, B; cin >> H >> W >> A >> B;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B ^ j < A) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}
