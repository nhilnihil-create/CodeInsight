#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;
    int cur = (n - 1) * (n - 2) / 2;
    if (cur < k) {
        cout << -1 << endl;
        return 0;
    }
    int c = 0;
    vector<pair<int, int>> link;
    repi(i, 1, n) link.push_back(pair<int, int>(0, i));
    repi(i, 1, n - 1)repi(j, i + 1, n) {
        if (cur - c == k) goto END;
        link.push_back(pair<int, int>(i, j));
        c++;
    }
END:
    cout << link.size() << endl;
    for (pair<int, int> p : link) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    return 0;
}

