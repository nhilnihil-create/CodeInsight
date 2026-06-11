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

#include <math.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    int Tsize = T.size();
    if (T.substr(0, Tsize-1) == S) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
  
