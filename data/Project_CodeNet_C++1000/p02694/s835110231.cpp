#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(_x) cout << _x << endl;
using namespace std;
int main()
{
    ll x;
    cin >> x;

    ll v = 100;
    int cnt = 0;
    while (v < x) {
        v += v / 100;
        cnt++;
    }

    put(cnt);
    return 0;
}