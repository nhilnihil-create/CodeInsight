#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

bool isok(string s) {
    return s.find("##") == string::npos;
}

bool isok2(string s, int a, int b) {
    bool res = false;
    for (int i = a; i <= b; ++i) {
        if (i+1 < s.size() && s.substr(i-1, 3) == "...") res = true;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;
    bool ans = false;
    if (c == d) {
        cout << "No" << endl;
        return 0;
    }
    if (c < d) {
        if (isok(s.substr(a, c-a+1)) && isok(s.substr(b, d-b+1))) ans = true;
    } else {
        if (isok(s.substr(a, c-a+1)) && isok2(s, b, d))ans = true;
    }
    cout << (ans?"Yes":"No") << endl;
}