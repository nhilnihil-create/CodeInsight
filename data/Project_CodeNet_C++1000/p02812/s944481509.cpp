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

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    int n, z = 0;
    string s;
    cin >> n >> s;
    for (int i = 2; i < s.length(); i++) if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C') z++;
    cout << z;
}
