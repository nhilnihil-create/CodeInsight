#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}
 
int main()
{
    int l;
    cin >> l;
    double x = l / 3.0;
    printf("%f\n", x * x * x);
    return 0;
}