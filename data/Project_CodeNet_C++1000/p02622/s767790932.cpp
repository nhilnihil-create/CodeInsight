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
    string s, t;
    int z = 0;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) if (s[i] != t[i]) z++;
    cout << z;
}
