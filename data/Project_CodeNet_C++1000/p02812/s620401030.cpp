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
#define debug freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 0x7fffffff;
const int MIN = 0x80000000;
const ll maxn = 1e6 + 10;

int n, cnt = 0;
string s;

int main() {
    ios;
    cin >> n >> s;
    for (int i = 0; i < n - 2; i ++){
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
            cnt ++;
            i += 2;
        }
    }
    cout << cnt << '\n';
    return 0;
}