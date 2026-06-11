#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 != 0) {
        cout << "No" << endl;
    }
    else if (s.substr(0, n/2) != s.substr(n/2)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}