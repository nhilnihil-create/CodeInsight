#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h> // sqrt
using namespace std;

int main() {
    long N;
    cin >> N;
    long n = N * 100;
    for (long i = n / 108 - 1; i < n + 100; i++) {
        if (n <= 108 * i && i * 108 < n + 100) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}