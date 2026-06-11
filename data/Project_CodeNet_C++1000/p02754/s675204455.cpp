#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    
    put(a * (n / (a + b)) + min(a, n % (a + b)))
    return 0;
}