#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll a;
    double b;
    cin >> a >> b;
    ll c = (ll)round(b * 100);
    cout << a * c / 100;
}
