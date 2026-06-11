#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    vector<vector<int>> HS(H, vector<int>(W, 0));
    vector<vector<int>> VS(H, vector<int>(W, 0));

    for (int iy = 0; iy < H; ++iy) {
        int con = 0;
        for (int ix = 0; ix < W; ++ix) {
            if (S[iy][ix] == '#') {
                int score = con;
                while (con > 0) {
                    HS[iy][ix-con] = score;
                    con--;
                }
                HS[iy][ix] == 0;
            } else {
                con += 1;
            }
        }
        if (con > 0) {
            const int score = con;
            while (con > 0) {   
                HS[iy][W-con] = score;
                con--;
            }
        }
    }

    for (int ix = 0; ix < W; ++ix) {
        int con = 0;
        for (int iy = 0; iy < H; ++iy) {
            if (S[iy][ix] == '#') {
                int score = con;
                while (con > 0) {
                    VS[iy-con][ix] = score;
                    con--;
                }
                VS[iy][ix] == 0;
            } else {
                con += 1;
            }
        }
        if (con > 0) {
            const int score = con;
            while (con > 0) {   
                VS[H-con][ix] = score;
                con--;
            }
        }
    }

    int ans = 0;

    for(int ix = 0; ix < W; ++ix) {
        for(int iy = 0; iy < H; ++iy) {
            ans = max({HS[iy][ix] + VS[iy][ix] - 1, ans});
        }
    }
    cout << ans << endl;

    return 0;
}