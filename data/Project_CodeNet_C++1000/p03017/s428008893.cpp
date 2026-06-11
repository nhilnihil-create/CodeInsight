#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int a, b, forA, forB;
    string str;
    int Max = 0;
    int sCnt = 0;
    int tmp = 0, tmp2 = 0;
    bool chk = false;

    cin >> num >> a >> b >> forA >> forB;
    cin >> str;
    for (int i = 0; i < num; i++) {
        if (str.at(i) == '.') {
            tmp++;
            if (tmp2 >= 2) {
                if ((a < i && i < forA) || (a > i && i > forA)) {
                    cout << "No";
                    return 0;
                }
                if ((b < i && i < forB) || (b > i && i > forB)) {
                    cout << "No";
                    return 0;
                }
            }
            tmp2 = 0;
        } else {
            tmp2++;
            Max = max(Max, tmp);
            if (tmp >= 3 && i-1 >= b && i-1 <= forB) chk = true;
            tmp = 0;
        }
    }

    if (forA <= forB){
        if (Max >= 2)
            cout << "Yes";
        else
            cout << "No";
    } else {
        if (chk == true)
            cout << "Yes";
        else
            cout << "No";
    }
    //
}