#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    string s1 = "", s2 = "";
    rep(i, w - a) s1 += '1', s2 += '0';
    rep(i, a) s1 += '0', s2 += '1';

    rep(i, h - b) cout << s1 << endl;
    rep(i, b) cout << s2 << endl;
    return 0;
}