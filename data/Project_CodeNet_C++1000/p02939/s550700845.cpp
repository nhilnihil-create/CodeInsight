#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    string bunkatu = "";
    string bunkatu_bef = "";
    for (int i = 0; i < s.size(); i++) {
        bunkatu += s[i];
        if (bunkatu == bunkatu_bef) {
            continue;  // 前の分割と同じならば、さらに分割文字を伸ばす。
        } else {
            // 前の分割と異なるならば、bunkatuは新しい分割として採用する。
            // それを bunkatu_bef に保存し、新しい分割との比較対象にする。
            bunkatu_bef = bunkatu;
            bunkatu = "";
            ans++;
        }
    }
    cout << ans << endl;
}