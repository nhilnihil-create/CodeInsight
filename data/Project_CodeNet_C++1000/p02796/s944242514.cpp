//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    vector<P> res(N);
    REP(i,N) {
        int X,L;
        cin >> X >> L;
        res[i].first = X+L;
        res[i].second = X-L;
    }
    sort(res.begin(),res.end());
    ll ans = 0;
    int pre = -1000000000;
    REP(i,N) {
        //cout << res[i].second << " " << res[i].first << endl;
        if(res[i].second >= pre) {
            ans++;
            pre = res[i].first;
        }
    }
    cout << ans << endl;
}

