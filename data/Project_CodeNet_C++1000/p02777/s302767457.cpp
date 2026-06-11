#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if(s == u) cout << a-1 << ' ' << b << endl;
    else cout << a << ' ' << b - 1<< endl;
}
