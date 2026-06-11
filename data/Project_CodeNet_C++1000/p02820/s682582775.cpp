// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#include <iostream>
#include<string>
using namespace std;

int main()
{
    int n, k, r, s, p;
    string t;

    cin >> n >> k;
    cin >> r >> s >> p;

    cin >> t;
    int sum = 0;
    int flag[100000];
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
    }
    for (int i = 0; i < t.size(); i++) {
        if (i < k) {
            if (t[i] == 'r') {
                sum += p;
                flag[i] = 1;
            }
            else if (t[i] == 's') {
                sum += r;
                flag[i] = 1;
            }
            else {
                sum += s;
                flag[i] = 1;
            }
        }
        else {
            if (t[i] == t[i - k] && flag[i - k] == 1) {
                continue;
            }
            else {
                if (t[i] == 'r') {
                    sum += p;
                    flag[i] = 1;
                }
                else if (t[i] == 's') {
                    sum += r;
                    flag[i] = 1;
                }
                else {
                    sum += s;
                    flag[i] = 1;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}

