#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) for(int i=(n)-1;0<=i;--i)
#define each(e,v) for(auto&& e:(v))
#define all(v) begin(v),end(v)
#define dump(x) cerr<<#x<<": "<<(x)<<endl
#define INF 100000000
#define IINF 9999999999999;
using vint = vector<int>;
using ll = long long;
using vll = vector<ll>;
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

bool earth[51][51];
ofstream outputfile("output.txt");
int depth = 0;
int inputw, inputh;

void erase_island(int h, int w) {
    //++depth;
    //outputfile << depth << endl;
    earth[h][w] = false;
    if(h != 0 && w != 0) {
        if (earth[h - 1][w - 1]) erase_island(h - 1, w - 1);
    }
    if(h != 0 && w != inputw - 1) {
        if (earth[h - 1][w]) erase_island(h - 1, w);
    }
    if(h != 0) {
        if(earth[h - 1][w + 1]) erase_island(h - 1, w + 1);
    }
    if(w != 0 && h != inputh - 1) {
        if(earth[h + 1][w - 1]) erase_island(h + 1, w - 1);
    }
    if(w != 0) {
        if(earth[h][w - 1]) erase_island(h, w - 1);
    }
    if(h != inputh - 1 && w != inputw - 1) {
        if(earth[h + 1][w + 1]) erase_island(h + 1, w + 1);
    }
    if(h != inputh - 1) {
        if(earth[h + 1][w]) erase_island(h + 1, w);
    }
    if(w != inputw - 1) {
        if(earth[h][w + 1]) erase_island(h, w + 1);
    }
    //cout << "# " << h << " " << w << endl;
    depth = 0;
}

int main() {
    while(cin >> inputw >> inputh, inputw + inputh) {
        int temp;
        rep(i, inputh) {
            rep(j, inputw) {
                cin >> temp;
                if(temp == 0) earth[i][j] = false;
                else earth[i][j] = true;
            }
        }

        int ans = 0;
        rep(i, inputh) {
            rep(j, inputw) {
                if(earth[i][j]) {
                    erase_island(i, j);
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
