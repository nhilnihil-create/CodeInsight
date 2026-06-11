#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    char c[10][10];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < 1 << (h+w); ++i) {
        int cnt = 0;
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                if ((i & (1 << j)) == 0 && (i & (1 << (h + k))) == 0 && c[j][k] == '#'){
                    cnt++;
                }
            }
        }
        if (cnt == k){
            res++;
        }
    }
    cout << res << endl;
}