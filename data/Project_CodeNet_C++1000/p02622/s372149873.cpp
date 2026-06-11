#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s, t;
    cin >> s  >> t;
    int c = 0;
    rep(i, s.size()) {
        if (s[i] != t[i]) c++;
    }
    println(c)
    return 0;
}