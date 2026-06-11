#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    string s;
    cin >> s;
    
    int sum = 0;
    rep(i, s.size()/2) {
        if (s[i] != s[s.size() - 1 - i]) sum ++;
    }
    println(sum)
    return 0;
}