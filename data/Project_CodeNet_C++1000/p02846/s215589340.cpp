#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    vector<ll> t(2), a(2), b(2);
    cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];
    if(b[0] > a[0]) {
        swap(a[0], b[0]);
        swap(a[1], b[1]);
    }

    ll ad = t[0] * a[0] + t[1] * a[1];
    ll bd = t[0] * b[0] + t[1] * b[1];
    cerr << bd - ad << endl;

    if(bd - ad < 0) {
        cout << 0 << endl;
    }
    if(bd - ad == 0) {
        cout << "infinity" << endl;
    }
    if(bd - ad > 0) {
        ll sa = a[0] *t[0] - b[0] * t[0];
        cout << (sa / (bd - ad))*2 + 1 - ((sa % (bd - ad)) == 0)<< endl;
    }

}