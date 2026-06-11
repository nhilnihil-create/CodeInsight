#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            return 0;
        }
        vector<vector<char>> v(h, vector<char>(w, '\0'));
        pair<int, int> start;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> v[i][j];
                if (v[i][j] == '@') {
                    start = make_pair(i, j);
                }
            }
        }
        constexpr char REACHABLE = '$';
        function<void(int, int)> f = [&v, &f, w, h, REACHABLE](int i, int j) {
            // ?????¢????¶???????
            if (i == -1 || j == -1 || i == h || j == w) {
                return;
            }
            // ?§??????§?????????
            else if (v[i][j] == '#') {
                return;
            }
            // ????????°?????§??????
            else if (v[i][j] == REACHABLE) {
                return;
            }
            else {
                v[i][j] = REACHABLE;
                f(i - 1, j);
                f(i + 1, j);
                f(i, j - 1);
                f(i, j + 1);
            }
        };
        f(start.first, start.second);
        auto r = accumulate(begin(v), end(v), 0,
                            [REACHABLE](int z, const vector<char>& vv) {
                                return z + count(begin(vv), end(vv), REACHABLE);
                            });
        cout << r << endl;
    }
}