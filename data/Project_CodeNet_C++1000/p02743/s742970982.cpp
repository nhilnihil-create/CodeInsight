#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    long long A = 4 * a * b;
    long long B = c - a - b;
    bool res = false;
    const long long MX = 2LL * 1000000001LL;
    if (B >= 0) {
        if (B >= MX) {
            res = true;
        } else {
            B *= B;
            if (B > A) {
                res = true;
            }
        }
    } else {

    }

    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}