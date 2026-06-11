#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    string s;
    cin >> s;
    string array[3];
    if(s == "Sunny") {
        cout << "Cloudy" << endl;
    } else if(s == "Cloudy") {
        cout << "Rainy" << endl;
    } else if(s == "Rainy") {
        cout << "Sunny" << endl;
    }
    return 0;
}
