#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    int x, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i % 2 == 1 && x % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}