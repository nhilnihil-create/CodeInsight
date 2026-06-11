#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ss = s.substr(0, n / 2);

    if ((ss + ss) == s)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
