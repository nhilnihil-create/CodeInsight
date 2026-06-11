#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans = 1;
    if (s == "RRR")
        ans = 3;
    else if (s == "RRS" || s == "SRR")
        ans = 2;
    else if (s == "SSS")
        ans = 0;
    cout << ans << '\n';
}