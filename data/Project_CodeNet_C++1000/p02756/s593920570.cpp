#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int Maxn = (int)1e5 + 1;
const ld pi = acos(-1);
const int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 0, (int)A.size()) out << A[i] << " ";
    return out;
}

template <class T>
ostream &operator<<(ostream &out, deque<T> &dq) {
    while (!dq.empty()) {
        out << dq.front() << " ";
        dq.pop_front();
    }
    return out;
}

int32_t main() {
    IOS deque<char> dq;
    string p;
    cin >> p;
    for (auto x : p) {
        dq.push_front(x);
    }
    bool flag = true;
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        if (n == 1) {
            flag = !flag;
        } else {
            char x, y;
            cin >> x >> y;
            if (flag) {
                if (x == '1') {
                    dq.push_back(y);
                } else {
                    dq.push_front(y);
                }
            } else {
                if (x == '1') {
                    dq.push_front(y);
                } else {
                    dq.push_back(y);
                }
            }
        }
    }
    // cout << dq << "ok" << endl;
    string s;
    if (flag) {
        while (!dq.empty()) {
            s += dq.back();
            dq.pop_back();
        }
    } else {
        while (!dq.empty()) {
            s += dq.front();
            dq.pop_front();
        }
    }
    cout << s;
    return 0;
}
