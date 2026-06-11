#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    string oth = "";
    while (oth.size() < s.size())
        oth += "hi";
    printf("%s\n", oth == s? "Yes": "No");
    return 0;
}
