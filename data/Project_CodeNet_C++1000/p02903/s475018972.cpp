#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i < B) {
                if(j < A) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else {
                if(j < A) {
                    cout << 0;
                }
                else {
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
}
