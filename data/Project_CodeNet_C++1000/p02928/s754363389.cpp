#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    long long a[2020];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                ans += k * (k + 1) / 2;
            }
            else if (a[i] < a[j]) {
                ans += k * (k - 1) / 2;
            }
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}