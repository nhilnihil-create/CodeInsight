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
    int X;
    cin >> X;
    for(int i = ceil(X/105); i <= X/100; i++) {
        for(int m = 100*i; m <= 105*i; m++) {
            if(m == X) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
}
