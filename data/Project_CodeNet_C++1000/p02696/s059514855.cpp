#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a, b, n;

ll func(ll x) {
    ll num1 = a * x ;
    ll num2 = x / b;
    ll num3 = num1 /b;
    ll num4 = num2 * a;
    return num3 - num4;
}

int main(){
    cin >> a >> b >> n;
    cout << func(min(b-1, n)) << endl;
}