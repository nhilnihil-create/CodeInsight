#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef unsigned long long int ulli;

int main() {
    int n;
    cin >> n;
    ulli res = 0;
    ulli resa[9][9];
    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
            resa[j][k] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        string si = to_string(i);
        int sil = si.length();
        int j = si[0] - '1';
        int k = si[sil - 1] - '1';
        if (k == -1)continue;
        resa[j][k]++;
    }
    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
            if (resa[j][k] == 0) {
                continue;
            }
            res += (resa[j][k]) * (resa[k][j]);
        }
    }
    cout << res << endl;
    return 0;
}