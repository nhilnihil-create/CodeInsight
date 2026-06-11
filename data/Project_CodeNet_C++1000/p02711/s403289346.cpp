#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char s[4];
    cin >> s;
    if(s[0] == '7' || s[1] == '7' || s[2] == '7')
        cout << "Yes";
    else
        cout << "No";
    cout << "\n";
    return 0;
}
