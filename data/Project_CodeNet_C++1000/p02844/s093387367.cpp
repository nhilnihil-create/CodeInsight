#include <iostream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

#define FOR(i, a, b) for (int i = a; i < (b); i++)

int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

int main () {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int can[10];
    FOR(i, 0, 10) {
        can[i] = 0;
    }
    // int can[10][10][10];
    // FOR(i, 0, 10) {
    //     FOR(j, 0, 10) {
    //         FOR(k, 0, 10) {
    //             can[i][j][k] = 0;
    //         }
    //     }
    // }
    int t[n];
    FOR(i, 0, n) {
        t[i] = ctoi(s[i]);
    }
    // FOR(i, 0, n-2) {
    //     FOR(j, i+1, n-1) {
    //         FOR(k, j+1, n) {
    //             can[t[i]][t[j]][t[k]] = 1;
    //         }
    //     }
    // }
    int ans = 0;
    int flag = 0;
    FOR(i, 0, 10) {
        FOR(j, 0, 10) {
            FOR(k, 0, n) {
                if (flag == 0) {
                    if (t[k] == i) flag = 1;
                } else if (flag == 1) {
                    if (t[k] == j) flag = 2;
                } else {
                    can[t[k]] = 1;
                    int l;
                    for (int l = 0; l < 10; l++) {
                        if (can[l] == 0) break;
                    }
                    if(l == 10) break;
                }
            }
            FOR(l, 0, 10) {
                if (can[l] == 1) ans++;
                can[l] = 0;
            }
            flag = 0;
        }
    }
    cout << ans << endl;
    return 0;
}