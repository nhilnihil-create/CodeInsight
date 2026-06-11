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
    int n, z = 1;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) if (s[i] != s[i - 1]) z++;
    cout << z;
}
