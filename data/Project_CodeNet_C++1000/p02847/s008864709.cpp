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
    string s[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}, t;
    cin >> t;
    for (int i = 0; i < 7; i++) if (s[i] == t) {
        if (i == 0) cout << 7;
        else cout << 7 - i;
    }
}
