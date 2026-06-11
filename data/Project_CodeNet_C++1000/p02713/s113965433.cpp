#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int gcd(int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    int k;
    ll z = 0;
    cin >> k;
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) for (int l = 1; l <= k; l++) z += gcd(i, gcd(j, l));
    cout << z;
}
