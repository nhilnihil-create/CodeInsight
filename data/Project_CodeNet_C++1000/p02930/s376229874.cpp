#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    int n, mn = 0;
    cin >> n;
    while (pow(2, mn) < n) mn++;
    mn--;
    
    int ans[505][505];
    for (int i = 0; i < n*n; i++) ans[i%n][i/n] = -1;
    
    for (int i = 0; i <= mn; i++) {
        for (int p = 0; p < n; p++) {
            for (int q = p + 1; q < n; q++) {
                //cout << p << " " << q << " " << (p & (1 << i)) <<" " << (q & (1 << i)) << endl;
                if (ans[p][q] == -1 && (((p & (1 << i)) ^ (q & (1 << i))) == pow(2, i))) {
                    ans[p][q] = i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j != i + 1) cout << " ";
            cout << ans[i][j] + 1;
        }
        cout << endl;
    }


}

/* 
g++ -std=c++14 _main.cpp
*/