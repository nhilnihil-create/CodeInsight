#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        string s;
        cin >> s;
        if (s == "SUN") cout << 7;
        else if (s == "MON") cout << 6;
        else if (s == "TUE") cout << 5;
        else if (s == "WED") cout << 4;
        else if (s == "THU") cout << 3;
        else if (s == "FRI") cout << 2;
        else cout << 1;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}