#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    for (char &c : s) if (c == '?') c = 'D';
    cout << s << endl;
    return 0;
}
