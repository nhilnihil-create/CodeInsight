#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 7;
    if (s == "SAT") res = 1;
    if (s == "FRI") res = 2;
    if (s == "THU") res = 3;
    if (s == "WED") res = 4;
    if (s == "TUE") res = 5;
    if (s == "MON") res = 6;

    cout << res << endl;

    return 0;
}
