#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    string strA = "";
    string strB = "";
    for (int i = 0; i < b; i++) strA += to_string(a);
    for (int i = 0; i < a; i++) strB += to_string(b);

    if (strA > strB) cout << strB << endl;
    else cout << strA << endl;
    return 0;
}