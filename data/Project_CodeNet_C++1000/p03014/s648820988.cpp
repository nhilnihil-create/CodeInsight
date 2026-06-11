#include <iostream>
using namespace std;

int l[2000][2000], r[2000][2000], up[2000][2000], down[2000][2000];
char a[2000][2000];

int main () {
    int h, w, temp = 0, res = 0;
    cin >> h >> w;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];
    for (int i = 0; i < h; i++) {
        temp = 0;
        for (int j = 0; j < w; j++) l[i][j] = (a[i][j] == '#') ? temp = 0 : ++temp;
    }
    for (int i = 0; i < h; i++) {
        temp = 0;
        for (int j = w-1; j >= 0; j--) r[i][j] = (a[i][j] == '#') ? temp = 0 : ++temp;
    }
    for (int i = 0; i < w; i++) {
        temp = 0;
        for (int j = 0; j < h; j++) up[j][i] = (a[j][i] == '#') ? temp = 0 : ++temp;
    }
    for (int i = 0; i < w; i++) {
        temp = 0;
        for (int j = h-1; j >= 0; j--) down[j][i] = (a[j][i] == '#') ? temp = 0 : ++temp;
    }
    for (int i = 0; i < h; i++) {
        temp = 0;
        for (int j = 0; j < w; j++) if (a[i][j] != '#') res = max(res, l[i][j] + r[i][j] + up[i][j] + down[i][j] - 3);
    }
    cout << res << endl;
    return 0;
}