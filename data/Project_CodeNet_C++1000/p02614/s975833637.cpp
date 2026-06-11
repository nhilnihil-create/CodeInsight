#include <iostream>
using namespace std;
int main()
{
    int h, w, k, cnt, ans = 0, b = 0;
    int c[6][6] = {}, hc[6] = {}, wc[6] = {};
    char tmp;
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            c[i][j] = (tmp == '#' ? 1 : 0);
            hc[i] += c[i][j];
            wc[j] += c[i][j];
            b += c[i][j];
        }
    }
    for (int n = 0; n < (1 << h); n++) {
        for (int m = 0; m < (1 << w); m++) {
            cnt = b;
            for (int i = 0; i < h; i++) {
                if ((n >> i) & 1) cnt -= hc[i];
            }
            for (int j = 0; j < w; j++) {
                if ((m >> j) & 1) cnt -= wc[j];
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (((n >> i) & 1) && ((m >> j) & 1)) {
                        cnt += c[i][j];
                    }
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}