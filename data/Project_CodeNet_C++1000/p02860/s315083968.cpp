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

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    if (n % 2) cout << "No";
    else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) cout << "Yes";
    else cout << "No";
}
