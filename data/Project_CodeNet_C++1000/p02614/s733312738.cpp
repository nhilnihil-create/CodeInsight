#include <bits/stdc++.h>
// #include "prettyprint.hpp"

using namespace std;
using ll = long long;

const int sz = 35;
int arr[sz][sz], row[sz], col[sz];

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    char ch;
    int tb = 0;
    for(int i = 0; i < h; i++) {
        int cs = 0;
        for(int j = 0; j < w; j++) {
            cin >> ch;
            arr[i][j] = (ch == '#');
            cs += arr[i][j];
            tb += arr[i][j];
        }
        row[i] = cs;
    }
    // cout << row << "\n";
    for(int j = 0; j < w; j++) {
        int cs = 0;
        for(int i = 0; i < h; i++) {
            cs += arr[i][j];
        }
        col[j] = cs;
    }
    // cout << col << "\n";

    int mh = (1 << h) - 1;
    int mw = (1 << w) - 1;
    int res = 0;
    for(int i = 0; i <= mh; i++) {
        for(int j = 0; j <= mw; j++) {
            int cnt = 0;
            for(int k = 0; k <= 30; k++) {
                if(i & (1 << k)) {
                    cnt += row[k];
                }
                if(j & (1 << k)) {
                    cnt += col[k];
                }
                // if((i & (1 << k)) && (j & (1 << k))) {
                //     cnt -= arr[i][j];
                // }
            }
            for(int k = 0; k <= 30; k++) {
                if((i & (1 << k)) == 0) continue;
                for(int l = 0; l <= 30; l++) {
                    if ((j & (1 << l)) == 0) continue;
                    cnt -= arr[k][l];
                }
            }
            if((tb - cnt) == k) {
                res++;
            }
        }
    }
    cout << res << "\n";



    return 0;
}

