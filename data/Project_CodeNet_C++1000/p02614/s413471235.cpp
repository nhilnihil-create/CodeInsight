#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans=0;
    rep(bit1,1<<h) {
        rep(bit2,1<<w) {
            int cnt=0;
            rep(i,h)rep(j,w) {
                if(bit1>>i&1) continue;
                if(bit2>>j&1) continue;
                if(s[i][j]=='#') cnt++;
            }
            if(cnt==k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}