#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;
    long long a[n];
    for (auto &x : a) {
        cin >> x;
    }
    long long money = 1000;
    long long have = 0;
    for (int i = 0; i < n-1; i ++) {
        if (have == 0 && a[i] < a[i + 1]) {
            have = money / a[i];
            money -= have * a[i];
        } else if (have > 0 && a[i] > a[i + 1]) {
            money += have * a[i];
            have = 0;
        }
    }
    money += a[n-1] * have;
    cout << money << endl;
    return 0;
}