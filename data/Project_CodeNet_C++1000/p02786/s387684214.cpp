#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v) {
    os << "(" << v.first << ", " << v.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "}";
    return os;
}

int main()
{
    ll h;
    cin >> h;
    ll acc = 1;
    ll op = 0;

    while (acc * 2 <= h) {
        acc *= 2;
        op = 2 * op + 1;
    }

    cout << acc + op << endl;
    return 0;
}