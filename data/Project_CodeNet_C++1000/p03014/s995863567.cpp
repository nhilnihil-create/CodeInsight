#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int h, w; cin >> h >> w;
    V<string> b(h);
    for(int i = 0; i < h; i++) cin >> b[i];

    V<V<int> > ans(h, V<int>(w, 0));
    for(int i = 0; i < h; i++){
        V<int> seen(w + 1);
        for(int j = 0; j < w; j++){
            if(b[i][j] == '#') continue;
            if(seen[j]) continue;
            int len = 0;
            while(j + len < w){
                if(b[i][j + len] == '#') break;
                len++;
            }
            for(int k = 0; k < len; k++){
                ans[i][j + k] += len;
                seen[j + k] = 1;
            }
        }
    }

    for(int j = 0; j < w; j++){
        V<int> seen(h + 1);
        for(int i = 0; i < h; i++){
            if(b[i][j] == '#') continue;
            if(seen[i]) continue;
            int len = 0;
            while(i + len < h){
                if(b[i + len][j] == '#') break;
                len++;
            }
            for(int k = 0; k < len; k++){
                ans[i + k][j] += len;
                seen[i + k] = 1;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res = max(res, ans[i][j] - 1);
        }
    }
    cout << res << endl;

    return 0;
}
