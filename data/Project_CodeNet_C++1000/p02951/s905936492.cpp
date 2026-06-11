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


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a - (b + c);

    if (ans >= 0) {
        cout << 0 << endl;
    }
    else {
        cout << abs(ans) << endl;
    }

    return 0;
}
