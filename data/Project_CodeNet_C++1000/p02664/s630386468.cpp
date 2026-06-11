// '?'を'D'に置き換えればスコアが最低1増える。前の文字が'P'ならさらに1増える
// '?'を'P'に置き換えると、後の文字が'D'のときスコアが1増える。
// すべて'D'に置き換えるのは最適ではなさそうな感じがする、、、
// 'P????D'という文字列があって、すべて'D'にすると、
// 'PDDDDD'になって、スコアが+5になる
// 'PDPDPD'にすると、スコアが+5,,
// いや、すべて'D'でもよさそうな気はする
#include <bits/stdc++.h>
using namespace std;

int main() {
    string T;
    cin >> T;
    for(char ch: T) {
        if(ch == '?') cout << 'D' ;
        else cout << ch;
    }
    cout << endl;
    return 0;
}