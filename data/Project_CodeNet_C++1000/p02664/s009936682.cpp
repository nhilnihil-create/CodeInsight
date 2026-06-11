#include <bits/stdc++.h>
using namespace std;
#define REPLACE(_str, _ptn, _replacement) regex_replace(_str, regex(_ptn), _replacement)
 
string s;
int main() {
    cin >> s;
    s = REPLACE(s, "P\\?", "PD");
    s = REPLACE(s, "\\?D", "PD");
    s = REPLACE(s, "\\?", "D");
    cout << s;
    return 0;
}