#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    set<string> s;
    int n;  cin >> n;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.insert(t);
    }

    cout << s.size() << endl;
    return 0;
}