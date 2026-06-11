#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    string a; cin >> a;
    if (a.back() == 's') a += "es";
    else a += 's';
    cout << a << endl;
    return 0;
}
