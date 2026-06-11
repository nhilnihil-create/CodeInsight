#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <queue>

typedef long long ll;

using namespace std;


int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll m1 = a * c;
    ll m2 = a * d;
    ll m3 = b * c;
    ll m4 = b * d;
    cout << max(m1, max(m2, max(m3, m4))) << endl;
}
