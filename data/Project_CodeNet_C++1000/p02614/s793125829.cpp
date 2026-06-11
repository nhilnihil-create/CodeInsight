#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int H, W, K;
string *c;
set<int> s;

int dfs(int i) {
    if (i == H + W) {
        int tmp = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (c[j][k] == '#' && s.find(j) == s.end() && s.find(k+H) == s.end())
                    tmp++;
            }
        }
        if (tmp == K)
            return 1;
        else
            return 0;
    }

    int ans = 0;
    s.insert(i);
    ans += dfs(i+1);
    s.erase(i);
    ans += dfs(i+1);

    return ans;
}

int main() {
    cin >> H >> W >> K;
    c = new string[H];
    for (int i = 0; i < H; i++)
        cin >> c[i];
    cout << dfs(0) << endl;

    return 0;
}