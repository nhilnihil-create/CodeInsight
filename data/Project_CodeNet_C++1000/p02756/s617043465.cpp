#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;
    int que1, que2;
    string tmpStr;
    bool Rchk = true;

    cin >> str >> num;

    for (int i = 0; i < num; i++) {
        cin >> que1;
        if (que1 == 1) {
            //反転
            Rchk = !Rchk;
        } else if (que1 == 2) {
            cin >> que2 >> tmpStr;
            if (que2 == 1) {
                //　先頭
                if (Rchk == true)
                    str = tmpStr + str;
                else
                    str += tmpStr;
            } else if (que2 == 2) {
                // 末尾
                if (Rchk == true)
                    str += tmpStr;
                else
                    str = tmpStr + str;
            }
        }
    }

    if (Rchk == false) reverse(str.begin(), str.end());
    cout << str;
}