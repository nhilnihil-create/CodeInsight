#include <bits/stdc++.h>
using namespace std;

string reverseStr(string target)
{
    string retStr = "";
    for (int i = target.length() - 1; i >= 0; i--) {
        retStr += target[i];
    }
    return retStr;
}

int main()
{
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    int t, f;
    string c;
    bool reverse = false;
    string str1 = "";
    string str2 = "";
    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 1) {
            reverse = !reverse;
        }
        else {
            cin >> f >> c;
            if (f == 1) {
                if (reverse) {
                    str2 += c;
                }
                else {
                    str1 += c;
                }
            }
            else {
                if (reverse) {
                    str1 += c;
                }
                else {
                    str2 += c;
                }
            }
        }
    }

    string ans;
    if (reverse) {
        ans = reverseStr(str2) + reverseStr(S) + str1;
    }
    else {
        ans = reverseStr(str1) + S + str2;
    }
    cout << ans << endl;
    return 0;
}