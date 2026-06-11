#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int h, w, a, b; cin >> h >> w >> a >> b;
    vector<vector<int>> g(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if((i < b && j < a) || (i >= b && j >= a))g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    for(auto i : g) {
        for(auto j : i)cout << j;
        cout << endl;
    }
}