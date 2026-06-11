#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        cout << s.at(i) << t.at(i);
    }
}