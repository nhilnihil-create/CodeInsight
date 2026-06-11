#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int zoro = 0;
    rep(i,n) {
        int d1,d2;
        cin >> d1 >> d2;
        if(d1 == d2) {
            zoro++;
        } else {
            zoro = 0;
        }
        if(zoro == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
