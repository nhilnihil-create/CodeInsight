#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;

int main() {
    int h,w,a,b; cin >>  h >> w >> a >> b;
    vector<vector<char>> grid(h,vector<char>(w,'0'));

    for (int i = 0; i < b; i ++) {
        for (int j = 0; j < a; j ++) {
            grid[i][j] = '1';
        }
    }

    for (int i = b; i < h; i ++) {
        for (int j = a; j < w ; j ++) {
            grid[i][j] = '1';
        }
    }

    for (int i = 0; i < h; i ++ ) {
        for (int j = 0; j < w; j ++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
  
}