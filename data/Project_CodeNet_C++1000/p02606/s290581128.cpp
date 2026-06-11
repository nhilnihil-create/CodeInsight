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
    int l, r, d;
    cin >> l >> r >> d;
    int ans = 0;
    for (int i = l; i <= r; i++)
        if (i % d == 0)
            ans++;
    cout << ans << endl;
    return 0;
}