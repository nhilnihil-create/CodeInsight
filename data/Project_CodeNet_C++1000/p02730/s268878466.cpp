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

    if (S != reverseStr(S)) {
        cout << "No" << endl;
        return 0;
    }
    int cnt = (S.length() - 1) / 2;
    string str = S.substr(0, cnt);
    if (str != reverseStr(str)) {
        cout << "No" << endl;
        return 0;
    }
    cnt = (S.length() + 3) / 2;
    str = S.substr(cnt - 1, S.length());
    if (str != reverseStr(str)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}