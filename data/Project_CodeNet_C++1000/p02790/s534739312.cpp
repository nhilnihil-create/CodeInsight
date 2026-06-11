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
    int a, b;
    cin >> a >> b;
    
    if (a < b) {
        rep(i, b) cout << a;
        cout << endl;
    }
    else {
        rep(i, a) cout << b;
        cout << endl;
    }
    return 0;
}