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
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a % 2 == 0 && a % 3 != 0 && a % 5 != 0) {
            cout << "DENIED";
            return 0;
        }
    }
    cout << "APPROVED";
}
