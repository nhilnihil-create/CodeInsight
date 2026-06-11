#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if(s[s.size()-1] != 's') {
        s += "s";
    } else {
        s += "es";
    }
    cout << s << endl;
}
