#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int mypow(int a, int n) {
    int res = 1;
    for (int i = 0; i < n; i ++) {
        res *= a;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int h, w, k;
    cin >> h >> w >> k;
    string mass[h];
    
    for (auto &x : mass) {
        cin >> x;
    }

    int count = 0;
    for (int i = 0; i < mypow(2, h); i ++) {
        for (int j = 0; j < mypow(2, w); j ++) {
            string tmp[h];
            for (int m = 0; m < h; m ++) {
                tmp[m] = mass[m];
            }

            for (int a = 0; a < h; a ++) {
                if ((i >> a) & 1) {
                    for (int b = 0; b < w; b ++) {
                        tmp[a][b] = '.';
                    }
                }
            }
            for (int b = 0; b < w; b ++) {
                if ((j >> b) & 1) {
                    for (int a = 0; a < h; a ++) {
                        tmp[a][b] = '.';
                    }
                }
            }

            int S = 0;
            for (int a = 0; a < h; a ++) {
                for (int b = 0; b < w; b ++) {
                    S += (tmp[a][b] == '#');
                }
            }
            count += (S == k);
        }
    }
    cout << count << endl;
    return 0;
}