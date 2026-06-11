#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll x, h1, h2;
    cin >> x;
    h1 = x / 500;
    x %= 500;
    h2 = x / 5;
    cout << h1 * 1000 + h2 * 5 << endl;
    return 0;
}
