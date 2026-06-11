#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int h, w, k;    cin >> h >> w >> k;
    vector<string>c(h);
    rep(i, h)   cin >> c[i];
    int ans = 0;
    rep(row, 1 << h)    rep(col, 1 << w){
        int black = 0;
        rep(i, h)   rep(j, w){
            if(row>>i&1)    continue;
            if(col>>j&1)    continue;
            if(c[i][j] == '#')  black++;
        }
        if(black == k)  ans++;
    }
    cout << ans << endl;
}
