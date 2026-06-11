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
    string S;
    int Q;
    cin >> S >> Q;
    deque<char> ans(S.size());
    for (int i = 0; i < S.size(); i++) {
        ans[i] = S[i];
    }
    int rev = 1;
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            rev = 3 - rev;
        }
        else {
            int b;
            char c;
            cin >> b >> c;
            if ((b + rev) % 2 == 0) {
                ans.push_front(c);
            }
            else {
                ans.push_back(c);
            }
        }
    }
    int N = ans.size();
    if (rev == 1) {
        for (int i = 0; i < N; i++) {
            cout << ans[i];
        }
    }
    else {
        for (int i = N - 1; i > -1; i--) {
            cout << ans[i];
        }
    }
    cout << endl;
}
