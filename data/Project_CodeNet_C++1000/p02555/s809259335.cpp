#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define PI acos(-1)
#define fs first
#define sc second
#define MAX 0x3f3f3f3f
#define debug freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#define ios                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2005;
const ll k = 1e9 + 7;
int s;
ll arr[maxn] = {0, 0, 0, 1, 1};

int main() {
    ios;
    cin >> s;
    for (int i = 4; i <= s; i++)
        arr[i] = (arr[i - 1] + arr[i - 3]) % k;
    cout << arr[s] << '\n';
    return 0;
}