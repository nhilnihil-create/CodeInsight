#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()
#define print(s) cout << (s) << endl

typedef pair<int,int> P;
const P NOT_EXIST = make_pair(-1,-1);

P getNonZero(vector<vector<int>> bd) {
    REP(i,bd.size()) {
        REP(j,bd[0].size()) {
            if (bd[i][j] != 0) return make_pair(i,j);
        }
    }
    return NOT_EXIST;
}

bool hasSameId(int x, int y, int id, vector<vector<int>> bd) {
    int H = bd.size();
    int W = bd[0].size();
    if (id == 0) return false;
    if (!(x >= 0 && x < H)) return false;
    if (!(y >= 0 && y < W)) return false;
    return bd[x][y] == id;
}

void printBoard(vector<vector<int>> bd) {
    REP(i,bd.size()) {
        REP(j,bd[0].size()) {
            cout << bd[i][j];
        }
        cout << endl;
    }
}

void solve118(int H, int W) {
    vector<vector<int>> bd(H,vector<int>(W));
    REP(i,H) {
        string s;
        cin >> s;
        REP(j,W) {
            if (s[j] == '#') bd[i][j] = 1;
            else if (s[j] == '*') bd[i][j] = 2;
            else bd[i][j] = 3;
        }
    }
    
    int ans = 0;
    P nonZero;
    while ((nonZero = getNonZero(bd)) != NOT_EXIST) {
        queue<P> q;
        q.push(nonZero);
        ans += 1;
        while (q.size()) {
            P fr = q.front();
            int x, y, id;
            x = fr.first;
            y = fr.second;
            id = bd[x][y];
            bd[x][y] = 0;
            if (hasSameId(x+1,y,id,bd)) q.push(make_pair(x+1, y));
            if (hasSameId(x-1,y,id,bd)) q.push(make_pair(x-1, y));
            if (hasSameId(x,y+1,id,bd)) q.push(make_pair(x, y+1));
            if (hasSameId(x,y-1,id,bd)) q.push(make_pair(x, y-1));
            q.pop();
        }
        //printBoard(bd);
    }
    cout << ans << endl;
}

int main() {
    int H, W;
    while (cin >> H >> W, H + W) {
        solve118(H,W);
    }
    return 0;
}