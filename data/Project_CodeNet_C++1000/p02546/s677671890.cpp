//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string s;
    cin >> s;
    if (s.back() == 's')
        s.push_back('e');
    s.push_back('s');
    cout << s;
}