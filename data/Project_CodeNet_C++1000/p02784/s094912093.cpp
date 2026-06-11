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
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        if (sum >= h) {
            println("Yes")
            return 0;
        }
    }
    
    println("No")
    return 0;
}