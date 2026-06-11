#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main() {
    int h,w,k;
    cin >> h >> w >> k;
    char c[h][w];
    rep(i,h) rep(j,w) cin >> c[i][j];

    int ans = 0, cnt;
    rep(is,1<<h){rep(js,1<<w){
        cnt = 0;
        rep(i,h){rep(j,w){
            if(is & (1<<i)) continue;
            if(js & (1<<j)) continue;
            if(c[i][j] == '#') cnt++;
        }
        }
        if(cnt == k) ans++;
    }
    }
    cout << ans << endl;
}