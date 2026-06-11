#include <bits/stdc++.h>
using namespace std;
char a[7][7];
int h, w, k, ans = 0, black;

int main() {
    cin >> h >> w >> k;
    cin.ignore();
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cin >> a[i][j];
    }

    for(int C = 0; C < (1 << h); C++) {
        for(int R = 0; R < (1 << w); R++) {
            black = 0;

            for(int i = 0; i < h; i++)
                for(int j = 0; j < w; j++) {
                    if(((C >> i) & 1) == 0 && ((R >> j) & 1) == 0 && a[i][j] == '#')
                        black++;
                }

            if(black == k)
                ans++;
            
        }
    }
    cout << ans;
}