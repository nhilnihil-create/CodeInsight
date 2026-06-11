#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, a, b; cin >> h >> w >> a >> b;
    vector<vector<bool>> m(h, vector<bool>(w, false));
    for (auto i = 0; i < b; i++) for (auto j = 0; j < a; j++) m[i][j] = true;
    for (auto i = b; i < h; i++) for (auto j = a; j < w; j++) m[i][j] = true;
    for (auto i = 0; i < h; i++) {
        for (auto j = 0; j < w; j++) cout << m[i][j];
        cout << endl;
    }
    return 0;
}