#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h), t;
    for (int i = 0; i < h; i++) cin >> s[i];
    
    int ans = 0;
    for (int bith = 0; bith < (1<<h); bith++) {
        for (int bitw = 0; bitw < (1<<w); bitw++) {
            t = s;
            for (int i = 0; i < h; i++) {
                if (bith & (1<<i)) {
                    for (int j = 0; j < w; j++) t[i][j] = 'R'; 
                }
            }
            for (int i = 0; i < w; i++) {
                if (bitw & (1<<i)) {
                    for (int j = 0; j < h; j++) t[j][i] = 'R'; 
                }
            }
            int count = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (t[i][j] == '#') count++;
                }
            }
            if (count == k) ans++;
        }
    }
    cout << ans << endl;
}