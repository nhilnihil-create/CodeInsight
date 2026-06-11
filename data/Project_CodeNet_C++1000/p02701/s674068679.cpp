#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    Int n;
    cin >> n;
    set<string> st;
    string s;
    for (Int i = 0; i < n; ++i) {
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
    return 0;
}
