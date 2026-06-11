#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << a / __gcd(a, b) * b;

    return 0;
}