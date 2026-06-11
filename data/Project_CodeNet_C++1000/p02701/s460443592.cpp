
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define repeat2(n) for (int j = 0; j < n; ++j)
#define all(x) (x).begin(), (x).end()

#define MAX_SIZE (100001)

signed main() {
    int n;
    cin >> n;

    set<string> se;

    repeat(n) {
        string s;
        cin >> s;

        se.insert(s);
    }

    cout << se.size();
    
    return 0;
}