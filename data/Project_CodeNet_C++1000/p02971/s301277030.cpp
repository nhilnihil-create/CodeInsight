#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vi data(N);
    int maxnum = 0;
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
        maxnum = max(maxnum, data.at(i));
    }
    vi count(maxnum + 1, 0);
    for (int x : data) {
        count.at(x)++;
    }
    bool check = true;
    if (count.at(maxnum) > 1) {
        check = false;
    }
    int secondnum = 0;
    for (int i = maxnum - 1; i > 0; i--) {
        if (count.at(i) != 0) {
            secondnum = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (data.at(i) == maxnum && check) {
            cout << secondnum << endl;
        }
        else {
            cout << maxnum << endl;
        }
    }
}