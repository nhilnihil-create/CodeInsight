#include <bits/stdc++.h>
using namespace std;

signed main() {
    string str;
    cin >> str;
    int N = 0;
    for (auto e : str)
        N += e - '0';
    if (N % 9)
        cout << "No";
    else
        cout << "Yes";
    cout << endl;
    system("pause");
    return 0;
}