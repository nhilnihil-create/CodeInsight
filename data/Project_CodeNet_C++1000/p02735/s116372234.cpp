#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > s(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < W; ++j) {
            s[i][j] = (row[j] == '#') ? 1 : 0;
        }
    }

    vector<vector<int> > minFlip(H, vector<int>(W, -1));
    for (int i = H - 1; i >= 0; --i) {
        for (int j = W - 1; j >= 0; --j) {
            if (i == H - 1 && j == W - 1) {
                minFlip[i][j] = (s[i][j] == 1) ? 1 : 0;
                continue;
            }
            int nflip = 1000;
            // go to i + 1
            if (i < H - 1) {
                nflip = min(
                    nflip,
                    minFlip[i + 1][j] + ((s[i][j] == 1 && s[i + 1][j] == 0) ? 1 : 0)
                );
            }
            // go to j + 1
            if (j < W - 1) {
                nflip = min(
                    nflip,
                    minFlip[i][j + 1] + ((s[i][j] == 1 && s[i][j + 1] == 0) ? 1 : 0)
                );
            }
            minFlip[i][j] = nflip;
        }
    }
    cout << minFlip[0][0] << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
