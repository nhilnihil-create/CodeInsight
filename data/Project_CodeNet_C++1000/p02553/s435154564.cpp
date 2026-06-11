#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    ll a, b, c, d;  cin >> a >> b >> c >> d;
    print(max({a*d, a*c, b*c, b*d}));
}