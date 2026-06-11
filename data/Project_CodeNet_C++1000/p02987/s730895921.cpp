#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;
    std::sort(s.begin(), s.end());
    yorn (s[0] == s[1] && s[2] == s[3] && s[1] != s[2]);
    return 0;
}