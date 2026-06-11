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
    V<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    V<V<int> > cnt(h, V<int>(w));
    for(int i = 0; i < h; i++){
        V<int> d(w);
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') continue;
            if(d[j]) continue;
            int l = 0;
            while(j + l < w){
                if(s[i][j + l] == '#') break;
                l++;
            }
            for(int k = 0; k < l; k++){
                cnt[i][j + k] += l;
                d[j + k] = 1;
            }
        }
    }
    for(int j = 0; j < w; j++){
        V<int> d(h);
        for(int i = 0; i < h; i++){
            if(s[i][j] == '#') continue;
            if(d[i]) continue;
            int l = 0;
            while(i + l < h){
                if(s[i + l][j] == '#') break;
                l++;
            }
            for(int k = 0; k < l; k++){
                cnt[i + k][j] += l;
                d[i + k] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans = max(ans, cnt[i][j] - 1);
        }
    }
    cout << ans << endl;


    return 0;
}
