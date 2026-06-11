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
    int k;
    string s;
    cin >> k >> s;
    if (s.length() <= k) cout << s;
    else cout << s.substr(0, k) << "...";
}
