
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i = 0; i< N; i++)

//abc-164
//c-gacha
int main() {
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    //vectorから重複を消すアルゴリズム
    //引用:uniqueは隣接する重複要素を削除するがvectorの長さは変更されないため、末尾にゴミが残る
    //なのでsortをして予めvectorをソートしておき、末尾のゴミを削除する
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << s.size() << endl;
}