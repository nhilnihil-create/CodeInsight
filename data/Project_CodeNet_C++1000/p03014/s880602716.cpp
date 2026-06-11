#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

char S[2000][2000];
int U[2000][2000];
int L[2000][2000];
int R[2000][2000];
int D[2000][2000];

int main() {
    int H, W;
    cin >> H >> W;
    rep(i, H) {
        rep(j, W) {
            cin >> S[i][j];

            U[i][j] = 0;
            L[i][j] = 0;
            R[i][j] = 0;
            D[i][j] = 0;
        }
    }

    rep(i, H) {
        rep(j, W) {
            // upper
            if(i == 0) {
                U[i][j] = S[i][j] == '#' ? 0 : 1;
            } else {
                U[i][j] = S[i][j] == '#' ? 0 : U[i-1][j] + 1;
            }

            // left
            if(j == 0) {
                L[i][j] = S[i][j] == '#' ? 0 : 1;
            } else {
                L[i][j] = S[i][j] == '#' ? 0 : L[i][j-1] + 1; 
            }

            int ri = H - i - 1;
            int rj = W - j - 1;

            // bottom
            if(ri == H-1) {
                D[ri][j] = S[ri][j] == '#' ? 0 : 1;
            } else {
                D[ri][j] = S[ri][j] == '#' ? 0 : D[ri+1][j] + 1; 
            }

            // right
            if(rj == W-1) {
                R[i][rj] = S[i][rj] == '#' ? 0 : 1;
            } else {
                R[i][rj] = S[i][rj] == '#' ? 0 : R[i][rj+1] + 1; 
            }
        }
    }

    int64_t ret = 0;
    rep(i, H) {
        rep(j, W) {
//            cout << D[i][j] << ", " ;
            ret = max(ret, (int64_t)(U[i][j] + L[i][j] + D[i][j] +R[i][j]));
        }
//        cout << endl;
    }
    cout << ret - 4 + 1 << endl;
    return 0;
}

