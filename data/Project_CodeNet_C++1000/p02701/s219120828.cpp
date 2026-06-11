#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <map>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> niz;
    while (n--) {
        string str;
        cin >> str;
        niz.insert(str);
    }
    cout << niz.size();
}