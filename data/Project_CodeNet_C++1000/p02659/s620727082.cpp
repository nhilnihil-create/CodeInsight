#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;




int main(){
    ll A;
    ld B;
    cin >> A >> B;
    ll ib = B*100+0.5;
    A *= ib;
    A /= 100;
    cout << A << endl;
}