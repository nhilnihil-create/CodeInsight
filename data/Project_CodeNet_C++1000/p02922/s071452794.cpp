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
    // 1 + n * (a - 1) >= b
    // n * (a - 1) >= b - 1
    cout << (b - 1 + (a - 2)) / (a - 1) << endl;
    return 0;
}