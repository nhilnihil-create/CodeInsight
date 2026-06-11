#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
static const int MAX_H = 2000;
static const int MAX_W = 2000;
static const int INF = 0;

//int d[MAX_H][MAX_W];

int H, W;

int main(){
    cin >> H >> W;

    vector<vector<char>> S(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S.at(i).at(j);
        }
    }

    int ans = 0;

    vector<vector<int>> dp_w(H, vector<int>(W, 0)), dp_h(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) == '.') {
                // H方向
                if (i > 0) dp_h.at(i).at(j) = dp_h.at(i - 1).at(j);
                if (dp_h.at(i).at(j) == 0) {
                    int k = i;
                    while (k < H && S.at(k).at(j) == '.') {
                        dp_h.at(i).at(j)++;
                        k++;
                    }
                }
                // W方向
                if (j > 0) dp_w.at(i).at(j) = dp_w.at(i).at(j - 1);
                if (dp_w.at(i).at(j) == 0) {
                    int k = j;
                    while (k < W && S.at(i).at(k) == '.') {
                        dp_w.at(i).at(j)++;
                        k++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) == '.') ans = max(ans, dp_h.at(i).at(j) + dp_w.at(i).at(j) - 1);
        }
    }

    cout << ans << endl;
    return 0;
}
