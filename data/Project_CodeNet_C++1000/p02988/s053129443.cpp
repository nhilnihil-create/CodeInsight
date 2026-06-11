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

bool asc(int a, int b, int c) {
    if(a < b && b < c) {
        return true;
    } else {
        return false;
    }
}

bool desc(int a, int b, int c) {
    if(a > b && b > c) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    int p[n];
    rep(i, n) { cin >> p[i]; }

    int count = 0;
    for(int i = 1; i < n - 1; ++i) {
        bool a = asc(p[i - 1], p[i], p[i + 1]);
        bool d = desc(p[i - 1], p[i], p[i + 1]);

        if(a || d) {
            count++;
        }
    }

    cout << count << endl;
}