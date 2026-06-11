#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int ans = 0;
    if(n % (2 * d + 1) == 0) {
        ans = n / (2 * d + 1);
    } else {
        ans = n / (2 * d + 1);
        ans++;
    }

    cout << ans << endl;
}