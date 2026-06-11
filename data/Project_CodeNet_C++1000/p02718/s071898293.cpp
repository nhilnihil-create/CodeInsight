#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<int> x(a);
    for (int i = 0; i < a; i++) {
        cin >> x[i];
    }
    double kaunto = 0;
    int count = 0;
    for (int i = 0; i < a; i++) {
        kaunto += x[i];
    }
    for (int i = 0; i < a; i++) {
        if (x[i] >= kaunto / (4 * b)) {
            count++;
        }
    }
    if (count >= b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;     
    }
}