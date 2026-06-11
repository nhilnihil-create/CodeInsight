#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (a >= k) {
        put(k);
    }
    else if (a + b >= k) {
        put(a)
    }
    else {
        put(a - (k - a - b))
    }
    
    return 0;
}