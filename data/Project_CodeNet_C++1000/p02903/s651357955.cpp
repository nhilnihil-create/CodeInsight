#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int H,W; cin >> H >> W;
    int A,B; cin >> A >> B;
    REP(i,H) {
        REP(j,W) {
            if(i+1 <= B) {
                if(j+1 <= A) cout << '0';
                else cout << '1';
            } else {
                if(j+1 <= A) cout << '1';
                else cout << '0';
            }
        }
        cout << endl;
    }
}