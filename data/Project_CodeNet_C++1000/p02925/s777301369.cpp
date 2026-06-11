#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

// #define MOD 1000000007
// #define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<queue<int>> A(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            int a;
            cin >> a;
            A[i].push(a-1);
        }
    }

    int ans = 0;
    set<int> updated_idxs;
    for (int i = 0; i < N; ++i) {
        updated_idxs.insert(i);
    }

    while (true) {
        // print("ans", ans);
        // print("A", A);
        // print("updated_idxs", updated_idxs);
        vector<bool> updated(N, false);
        set<int> new_updated_idxs;

        for (int i : updated_idxs) {
            if (!A[i].empty() && new_updated_idxs.count(i) == 0) {
                int j = A[i].front();
                if (!A[j].empty() && new_updated_idxs.count(j) == 0 && A[j].front() == i) {
                    A[i].pop(); A[j].pop();
                    new_updated_idxs.insert(i); new_updated_idxs.insert(j);
                }
            }
        }

        if (new_updated_idxs.empty()) {
            break;
        }
        updated_idxs = new_updated_idxs;
        ans += 1;
    }

    bool nonempty_any = false;
    for (int i = 0; i < N; ++i) {
        if (!A[i].empty()) {
            nonempty_any = true;
        }
    }

    if (nonempty_any) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
