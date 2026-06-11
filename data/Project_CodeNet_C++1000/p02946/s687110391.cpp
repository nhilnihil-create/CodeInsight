#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;

    int right = 0;
    int left = 0;

    left = max(-1000000, x - (k - 1));
    right = min(1000000, x + k - 1);

    for(int i = left; i <= right; ++i) {
        cout << i << " ";
    }
    cout << endl;
}