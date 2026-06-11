#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    ll s;
    cin >> s;

    ll x2 = s / 1000000000;
    ll y2 = s % 1000000000;

    if(y2 != 0){
        y2 = 1000000000 - y2;
        x2++;
    }

    cout << "0 0 1 1000000000 " << x2 << " " << y2;

    return 0;
}
