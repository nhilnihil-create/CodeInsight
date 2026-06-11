// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    int q;

    cin >> s;

    cin >> q;
    string s1, s2;

    //for (int i = 0; i < q; i++) {
    //    int a,f;
    //    string c;
    //    cin >> a;

    //    if (a == 1) {
    //        reverse(s.begin(), s.end());
    //    }
    //    else {
    //        cin >> f >> c;

    //        if (f == 1) {
    //            s = c + s;
    //        }
    //        else {
    //            s = s + c;
    //        }
    //    }
    //}
    int flag = 0;
    for (int i = 0; i < q; i++) {
        int a, f;
        string c;
        cin >> a;
        if (a == 1) {
            if (flag == 0) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
        else {
            cin >> f >> c;

            if (flag == 0) {
                if (f == 1) {
                    s1 = c + s1;
                }
                else {
                    s2 = s2 + c;
                }
            }
            else {
                if (f == 1) {
                    s2 = s2 + c;
                }
                else {
                    s1 = c+s1;
                }

            }
        }

    }
    if (flag == 0) {
        s = s1 + s + s2;
    }
    else {
        reverse(s.begin(), s.end());
         reverse(s1.begin(), s1.end());
         reverse(s2.begin(), s2.end());
        s = s2 + s + s1;
    }
    cout << s << endl;
    return 0;

}

