#include <iostream>
#include <vector>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<vector<int>> ans(h, vector<int>(w, 1e6));
    ans[0][0] = (s[0][0] == '#');
    for (int i = 0; i < h - 1; i++) {
        ans[i+1][0] = ans[i][0] + (s[i][0] == '.' && s[i+1][0] == '#');
    }
    for (int i = 0; i < w - 1; i++) {
        ans[0][i+1] = ans[0][i] + (s[0][i] == '.' && s[0][i+1] == '#');
    }
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            int num1 = ans[i-1][j] + (s[i-1][j] == '.' && s[i][j] == '#');
            int num2 = ans[i][j-1] + (s[i][j-1] == '.' && s[i][j] == '#');
            chmin(ans[i][j], num1);
            chmin(ans[i][j], num2);
        }
    }
    cout << ans[h-1][w-1] << endl;
}