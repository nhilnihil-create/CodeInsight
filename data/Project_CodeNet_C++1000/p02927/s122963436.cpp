#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <queue>
#include <tuple>
#include <map>
#include <cctype>
#include <math.h>
using namespace std;
using ll = long long;
using VI = vector<int>;


bool check(int d, int m) {
    if (d % 10 >= 2 && d / 10 >= 2 && (d % 10) * (d / 10) == m) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            if (check(j, i)) {
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
