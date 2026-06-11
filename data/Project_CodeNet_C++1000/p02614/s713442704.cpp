#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<char>> grid;
    int H, W, K;
public:
    void load() {
        cin >> H >> W >> K;
        grid.assign(H, vector<char>(W));
        for (int i = 0; i < H; ++i) {
            string s; cin >> s;            
            for (int j = 0; j < W; ++j) {
                grid[i][j] = s[j];
            }
        }
    }
    
    int solve() {
        int res{0};
        for (int mask_r = 0; mask_r < (1 << H); ++mask_r) {
            for (int mask_c = 0; mask_c < (1 << W); ++mask_c) {
                int cnt{0};
                for (int i = 0; i < H; ++i) {
                    for (int j = 0; j < W; ++j) {
                        if ((((mask_r >> i) & 1) == 0) && (((mask_c >> j) & 1) == 0) && grid[i][j] == '#') {                            
                            cnt++;
                        }
                    }
                }
                if (cnt == K) {
                    res++;
                }
            }            
        }
        return res;
    }
};

int main() {
    Solution sol;
    sol.load();
    cout << sol.solve() << endl;
}
