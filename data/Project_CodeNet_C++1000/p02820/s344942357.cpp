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
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N, K, R, S, P;
    string T;
    int ans = 0;
    cin >> N >> K >> R >> S >> P >> T;
    for (int i = 0; i < K; i++) {
        vector<char> data;
        for (int j = i; j < N; j += K) {
            data.push_back(T[j]);
        }
        int count = 1;
        int n = data.size();
        for (int j = 1; j < n; j++) {
            if (data[j - 1] == data[j]) {
                count++;
            }
            else {
                int a = floor((count + 1) / 2);
                if (data[j - 1] == 'r') {
                    ans += a * P;
                }
                else if (data[j - 1] == 's') {
                    ans += a * R;
                }
                else {
                    ans += a * S;
                }
                count = 1;
            }
        }
        int a = floor((count + 1) / 2);
        if (data[n - 1] == 'r') {
            ans += a * P;
        }
        else if (data[n - 1] == 's') {
            ans += a * R;
        }
        else {
            ans += a * S;
        }
    }
    cout << ans << endl;
}
