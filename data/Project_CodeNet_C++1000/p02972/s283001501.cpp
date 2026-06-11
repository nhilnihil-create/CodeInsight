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
#include <iomanip> // setprecision
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vi data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    vi ans(N, 0);
    int ansa = 0;
    for (int i = N - 1; i >= 0; i--) {
        int count = 0;
        int max = floor(N / (i + 1)) * (i + 1) - 1;
        for (int j = max; j >= i; j -= i + 1) {
            count += ans[j];
        }
        count %= 2;
        if (count != data[i]) {
            ans[i]++;
            ansa++;
        }
    }
    cout << ansa << endl;
    for (int i = 0; i < N; i++) {
        if (ans[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}
