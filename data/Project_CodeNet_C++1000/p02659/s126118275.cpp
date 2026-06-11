#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    ll a; cin >>a;
    long double b; cin >> b;
    ll c = (b+0.001)*100;
    ll d = a*c;
    ll e = d/100;
    cout << e << endl;
}