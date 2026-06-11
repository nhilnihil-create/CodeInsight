#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    string s = "No";
    if (a == b && a != c){
        s = "Yes";
    } else if (a == c && a != b) {
        s = "Yes";
    } else if (b == c && c != a) {
        s = "Yes";
    }
    cout << s;
    return 0;
}