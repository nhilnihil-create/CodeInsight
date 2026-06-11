#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
static const int INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w, '0'));
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> s.at(ih).at(iw);
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, INF));
    if(s.at(0).at(0)=='#') dp.at(0).at(0) = 1;
    else dp.at(0).at(0) = 0;

    int ihnext, iwnext, dpadd, R = 0, D = 1;
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            for(int id=R;id<=D;id++) {
                if(id==R) {
                    ihnext = ih+1;
                    iwnext = iw;
                }
                else {
                    ihnext = ih;
                    iwnext = iw+1;
                }
                if(ihnext>=h||iwnext>=w) continue;
                if(s.at(ihnext).at(iwnext)=='#'&&s.at(ih).at(iw)=='.') dpadd = 1;
                else dpadd = 0;
                chmin(dp.at(ihnext).at(iwnext), dp.at(ih).at(iw)+dpadd);
            }
        }
    }

    cout << dp.at(h-1).at(w-1) << endl;
    return 0;
}
