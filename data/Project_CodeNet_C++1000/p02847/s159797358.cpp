#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int ans;
    if (s == "SUN") {
        ans = 7;
    }
    else if (s == "MON") {
        ans = 6;
    }
    else if (s == "TUE") {
        ans = 5;
    }
    else if (s == "WED") {
        ans = 4;
    }
    else if (s == "THU") {
        ans = 3;
    }
    else if (s == "FRI") {
        ans = 2;
    }
    else {
        ans = 1;
    }
    cout << ans << endl;
}