#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int main() {
    long long n, ans = 0;
    cin >> n;
    ans += (n / 500) * 1000;
    n %= 500;
    ans += (n / 5) * 5;
    cout << ans << endl;
    return 0;
}
