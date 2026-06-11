#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;

string reverse(string x) {
    auto y = x;
    reverse(y.begin(), y.end());
    return y;
}

int main()
{
    string s;
    cin >> s;
    auto s1 = s.substr(0, (s.size() - 1) / 2);
    auto s2 = s.substr((s.size() + 3) / 2 - 1);
    yorn(s == reverse(s) && s1 == reverse(s1) && s2 == reverse(s2))
    return 0;
}