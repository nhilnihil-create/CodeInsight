#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int main() {
    int x, y, k_o;
    cin >> y >> x >> k_o;
    cin.get();
    vector<vector<char>> map(x, vector<char>(y));
    int no_black = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cin.get(map[j][i]);
            if (map[j][i] == '#') {
                no_black++;
            }
        }
        cin.get();
    }
    //Complete search
    int ans = 0;
    for (int i = 0; i < (int)pow(2, x + y); i++) {
        int temp_black = no_black;
        int column = i & ((int)pow(2, x) - 1);
        int row = i >> x;
        for (int j = 0; j < x; j++) {
            bool get_c = column & 1;
            column >>= 1;
            if (get_c) {
                for (int k = 0; k < y; k++) {
                    if (map[j][k] == '#') {
                        temp_black--;
                        map[j][k] = 'r';
                    }
                }
            }
        }
        for (int k = 0; k < y; k++) {
            bool get_r = row & 1;
            row >>= 1;
            if (get_r) {
                for (int j = 0; j < x; j++) {
                    if (map[j][k] == '#') {
                        temp_black--;
                        map[j][k] = 'r';
                    }
                }
            }
        }
        if (temp_black == k_o) {
            ans++;
        }
        for (int c = 0; c < x; c++) {
            for (int r = 0; r < y; r++) {
                if (map[c][r] == 'r') {
                    map[c][r] = '#';
                }
            }
        }
    }
    cout << ans;
}