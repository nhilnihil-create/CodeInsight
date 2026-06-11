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

void clear(queue<int> &que) {
    queue<int> empty;
    swap(que, empty);
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vi> data(N + 1);
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            data[i].push_back(i - 1);
        }
        if (i != N) {
            data[i].push_back(i + 1);
        }
        if (X == i) {
            data[i].push_back(Y);
        }
        else if (Y == i) {
            data[i].push_back(X);
        }
    }
    vi ans(N, 0);
    for (int i = 1; i <= N; i++) {
        vi dist(N + 1, -1);
        queue<int> que, que2;
        dist[i] = 0;
        que2.push(i);
        int count = 0;
        while (!que2.empty()) {
            count++;
            que = que2;
            clear(que2);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (int x : data[v]) {
                    if (dist[x] != -1) {
                        continue;
                    }
                    dist[x] = count;
                    que2.push(x);
                }
            }
        }
        for (int j = 1; j <= N; j++) {
            ans[dist[j]]++;
        }
    }
    for (int i = 1; i < N; i++) {
        cout << ans[i] / 2 << endl;
    }
}
