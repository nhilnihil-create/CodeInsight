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
    Int a, b;
    string b_temp;
    cin >> a >> b_temp;
    reverse(b_temp.begin(), b_temp.end());
    b_temp.erase(b_temp.begin() + 2);
    reverse(b_temp.begin(), b_temp.end());
    b = stoi(b_temp);
    cout << a * b / 100 << endl;
    return 0;
}

