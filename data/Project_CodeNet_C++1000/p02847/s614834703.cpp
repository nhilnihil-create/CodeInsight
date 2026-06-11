#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    string array[7] = { "SUN", "MON", "TUE", "WED",
                       "THU", "FRI", "SAT" };
    string s;
    cin >> s;
    rep(i, 7) {
        if (array[i] == s) {
            cout << 7 - i << endl;
        }
    }
    return 0;
}