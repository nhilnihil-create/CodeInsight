//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int X,Y; cin >> X >> Y;
    ll ans = 0;
    int score[3] = {300000,200000,100000};
    if(X <= 3) ans += score[X-1];
    if(Y <= 3) ans += score[Y-1];
    if(X == 1 && Y == 1) ans += 400000;
    cout << ans << endl;
}
