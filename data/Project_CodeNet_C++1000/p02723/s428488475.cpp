#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    string out = "No";
    if (s[2] == s[3] && s[4] == s[5]) out = "Yes";
    cout << out << endl;
    return 0;
}
