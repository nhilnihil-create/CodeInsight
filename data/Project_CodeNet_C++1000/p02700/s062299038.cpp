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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (1) {
        c -= b;
        if (c <= 0) {
            cout << "Yes";
            break;
        }
        a -= d;
        if (a <= 0) {
            cout << "No";
            break;
        }
    }
}
