#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int co[2020][2020] = { 0 };
int co1[2020][2020] = { 0 };
int main() {
    int h, w;
    cin >> h >> w;
    string s[2020];
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        int c = 0;
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                c++;
            }
            else {
                c = 0;
            }
            co[i][j] = c;
        }
        for (int j = w - 2; j >= 0; j--){
            if (co[i][j] != 0 && co[i][j + 1] != 0) {
                co[i][j] = co[i][j + 1];
            }
        }
    }
    for (int i = 0; i < w; i++) {
        int c = 0;
        for (int j = 0; j < h; j++) {
            if (s[j][i] == '.') {
                c++;
            }
            else {
                c = 0;
            }
            co1[j][i] = c;
        }
        for (int j = h - 2; j >= 0; j--) {
            if (co1[j][i] != 0 && co1[j + 1][i] != 0) {
                co1[j][i] = co1[j + 1][i];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (co[i][j] + co1[i][j] - 1 > ans) {
                ans = co[i][j] + co1[i][j] - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}