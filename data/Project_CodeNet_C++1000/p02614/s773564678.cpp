#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int h = 0, w = 0, k = 0;
    cin >> h >> w >> k;

    char arr[h][w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < pow(2, h); i++) {
        for(int j = 0; j < pow(2, w); j++) {
            int cnt = 0;
            for(int k = 0; k < h; k++) {
                if(i >> k & 1) continue;
                for(int l = 0; l < w; l++) {
                    if(j >> l & 1) continue;
                    if(arr[k][l] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }

    cout << ans << endl;


    return 0;
}