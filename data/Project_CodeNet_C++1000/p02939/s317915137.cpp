#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    int flag = 0;
    while (s.size() > 1)
    {
        if (s.at(0) != s.at(1) || flag)
        {
            ans++;
            flag = 0;
            s = s.substr(1, s.size() - 1);
        }
        else
        {
            ans++;
            flag = 1;
            s = s.substr(2, s.size() - 2);
        }
    }
    cout << ans + s.size() << endl;
}