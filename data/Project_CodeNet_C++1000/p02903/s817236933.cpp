#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int val = 0;
            if (j >= a)
                val = 1 - val;
            if (i >= b)
                val = 1 - val;
            cout << val;
        }
        cout << "\n";
    }
}
