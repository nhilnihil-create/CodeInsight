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
    long H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }
    long sum = H * W;
    long ans;
    if (sum % 2 == 0) {
        ans = sum / 2;
    }
    else {
        ans = (sum + 1) / 2;
    }
    cout << ans << endl;
}