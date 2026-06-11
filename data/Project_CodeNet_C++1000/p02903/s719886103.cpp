#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    
    vector<vector<int>> ans(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            if ((i < B && j < A) || (B <= i && A <= j)) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}