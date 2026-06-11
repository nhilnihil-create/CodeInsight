#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int H, W, K;
    vector<string> s;
    string  tmp;
    int     black, ans = 0;
    
    cin >> H >> W >> K;
    
    for ( int ii = 0; ii < H; ii++ ) {
        cin >> tmp;
        s.push_back(tmp);
    }
    
    for ( int maskR = 0; maskR <= (1 << H) - 1; maskR++ ) {
        for ( int maskC = 0; maskC <= (1 << W) - 1; maskC++ ) {
            black = 0;
            for ( int ii = 0; ii < H; ii++ ) {
                for ( int jj = 0; jj < W; jj++ ) {
                    if ( ((maskR >> ii) & 1) == 0 && ((maskC >> jj) & 1) == 0 &&  s[ii][jj] == '#' ) {
                        black++;
                    }
                }
            }
            if ( black == K ) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}