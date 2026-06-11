#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

inline int sum(vector<vector<int>>& v, set<int>& rows, set<int>& cols) {
    int out = 0;
    for (int i = 0; i < v.size(); i++) {
        if (rows.count(i))
            continue;
        for (int j = 0; j < v[i].size(); j++) {
            if (cols.count(j))
                continue;
            out += v[i][j];
        }
    }
    return out;
}

typedef long long ll;
int main() {
    int h, w, k; cin >> h >> w >> k;
    vector<vector<int>> v(h); char temp;
    for (int i = 0; i < h; i++) {
        v[i].resize(w);
        for (int j = 0; j < w; j++) {
            cin >> temp;
            if (temp == '#')
                v[i][j] = 1;
            else
                v[i][j] = 0;
        }
    }
    int result = 0;
    set<int> rows;
    set<int> cols;
    // if (sum(v, rows, cols) == k) result++;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            vector<int> selector(h);
            fill(selector.begin(), selector.begin() + i, 1);
            do {
                for (int i = 0; i < h; i++) {
                    if (selector[i]) {
                        rows.insert(i);
                    }
                }
                vector<int> selectorcol(w);
                fill(selectorcol.begin(), selectorcol.begin() + j, 1);
                do {
                    for (int i = 0; i < w; i++) {
                        if (selectorcol[i]) {
                            cols.insert(i);
                        }
                    }
                    if (sum(v, rows, cols) == k) {
                        result++;
                    }// {
                    // for (int t : rows) cout << t << " ";
                    // cout << "\n";
                    // for (int t : cols) cout << t << " ";
                    // cout << "\n\n";
                    // }
                    cols.clear();
                } while (prev_permutation(selectorcol.begin(), selectorcol.end()));
                rows.clear();
            } while (prev_permutation(selector.begin(), selector.end()));

        }
    }
    cout << result;

}

// std::string bitmaski(i, 1);
// bitmaski.resize(h+1, 0);

// do {
//     for (int x = 0; x < h; ++x)
//         if (bitmaski[x]) rows.insert(x);

//     std::string bitmaskj(j, 1);
//     bitmaskj.resize(w+1, 0);
//     do {
//         for (int z = 0; z < w; ++z)
//             if (bitmaski[z]) cols.insert(z);

//         if (sum(v, rows, cols) == k) {
//             result++;
//         } {
//             for (int t : rows) cout << t << " ";
//             cout << "\n";
//             for (int t : cols) cout << t << " ";
//             cout << "\n";
//         }
//     } while (std::prev_permutation(bitmaskj.begin(), bitmaskj.end()));

// } while (std::prev_permutation(bitmaski.begin(), bitmaski.end()));