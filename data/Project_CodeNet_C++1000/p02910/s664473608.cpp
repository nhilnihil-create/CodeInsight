// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    bool judge = true;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            if (s[i] == 'L') {
                judge = false;
                break;
            }
        }
        else {
            if (s[i] == 'R') {
                judge = false;
                break;
            }
        }
    }

    if (judge) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
    
}

