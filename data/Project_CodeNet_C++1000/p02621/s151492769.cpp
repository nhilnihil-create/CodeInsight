#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

int main() {
    int a;
    cin >> a;
    int ans = a + a * a + a * a * a;
    cout << ans << endl;
}
