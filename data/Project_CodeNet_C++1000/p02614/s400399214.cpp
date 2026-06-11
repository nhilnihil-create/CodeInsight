#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int h, w, k;   cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s[i];
    int ans = 0;
    for (int x = 0; x < (1<<h); x++) {
        for (int y = 0; y < (1<<w); y++) {
            vector<string> t = s;
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    if ((x>>k)&1 || (y>>l)&1)
                        t[k][l] = 'r';
                }
            }
            int cnt = 0;
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    if (t[k][l] == '#')
                        cnt++;
                }
            }
            if (cnt == k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}