#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i, s.size()) {
        int x = s[i] - 'A';
        x = (x + n) % ('Z' - 'A' + 1);
        char c = x + 'A';
        cout << c; 
    }
    cout << endl;
    return 0;
}