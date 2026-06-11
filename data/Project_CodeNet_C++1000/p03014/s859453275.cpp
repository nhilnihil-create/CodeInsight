#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];
    int u[h][w], d[h][w], r[h][w], l[h][w];
    for (int i = 0; i < h; i++){
        int num = 0;
        for (int j = 0; j < w; j++){
            if(s[i][j] == '.') num++;
            else num = 0;
            r[i][j] = num;
        }
    }
    for (int i = 0; i < h; i++){
        int num = 0;
        for (int j = w - 1; j >= 0; j--){
            if(s[i][j] == '.') num++;
            else num = 0;
            l[i][j] = num;
        }
    }
    for (int i = 0; i < w; i++){
        int num = 0;
        for (int j = 0; j < h; j++){
            if(s[j][i] == '.') num++;
            else num = 0;
            u[j][i] = num;
        }
    }
    for (int i = 0; i < w; i++){
        int num = 0;
        for (int j = h - 1; j >= 0; j--){
            if(s[j][i] == '.') num++;
            else num = 0;
            d[j][i] = num;
        }
    }
    int ans = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#') continue;
            ans = max(ans, r[i][j] + l[i][j] + u[i][j] + d[i][j] - 3);
        }
    }
    cout << ans << endl;
}