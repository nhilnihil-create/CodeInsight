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
    string s;
    int z = 0;
    cin >> s;
    for (int i = 0; i + i < s.length(); i++) if (s[i] != s[s.length() - i - 1]) z++;
    cout << z;
}
