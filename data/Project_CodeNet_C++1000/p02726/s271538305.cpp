#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// dist[i][j] ... i <= j
int dist[2000][2000];

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n - 1; i++)
        dist[i][i + 1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i <= x) {
                if (j <= x) {
                    dist[i][j] = j - i;
                } else if (x < j && j < y) {
                    // i <= x < j < y
                    dist[i][j] = min(j - i, (y - j) + 1 + (x - i));
                } else {
                    // i <= x < y <= j
                    dist[i][j] = min(j - i, (j - y) + 1 + (x - i));
                }
            } else if (i < y) {
                // x < i < y
                if (j < y) {
                    // x < i < j < y
                    dist[i][j] = min(j - i, (y - j) + 1 + (i - x));
                } else {
                    // x < i < y <= j
                    dist[i][j] = min(j - i, (j - y) + 1 + (i - x));
                }
            } else {
                // y <= i < j
                dist[i][j] = j - i;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%3d ", dist[i][j]);
    //     }
    //     cout << endl;
    // }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[dist[i][j]]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}