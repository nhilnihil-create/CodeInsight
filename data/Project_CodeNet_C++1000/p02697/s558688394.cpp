#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <cassert>
#include <memory>
using namespace std;
typedef long long ll;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    int N,M;
    cin >> N >> M;

    int i1 = 1;
    int i2 = M + 2;

    for (int diff = M; diff >= 1; diff--) {
        if (diff % 2 == M % 2) {
            cout << i1 << " " << i1 + diff << endl;
            i1++;
        }
        else {
            cout << i2 << " " << i2 + diff << endl;
            i2++;
        }
    }

    return 0;
}
