#include <bits/stdc++.h>
using namespace std;
 
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ", "; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ", "; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << ", " << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define f first
#define s second
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> arr(h);
    for(int i = 0; i < h; i++)
        cin >> arr[i];
    
    vector<vector<int>> dp(h, vector<int> (w));
    for(int i = w - 1; i >= 0; i--) {
        if(i == w - 1) {
            if(arr[h - 1][i] == '#')
                dp[h - 1][i] = 1;
            else
                dp[h - 1][i] = 0;
        } else {
            if(arr[h - 1][i] == '#' && arr[h - 1][i + 1] == '.')
                dp[h - 1][i] = dp[h - 1][i + 1] + 1;
            else
                dp[h - 1][i] = dp[h - 1][i + 1];
        }
    }
    for(int i = h - 2; i >= 0; i--) {
        for(int j = w - 1; j >= 0; j--) {
            if(j == w - 1) {
                dp[i][j] = dp[i + 1][j];
                if(arr[i][j] == '#' && arr[i + 1][j] != '#')
                    dp[i][j]++;
            } else {
                int a = dp[i + 1][j], b = dp[i][j + 1];
                if(arr[i][j] == '#' && arr[i + 1][j] != '#')
                    a++;
                if(arr[i][j] == '#' && arr[i][j + 1] != '#')
                    b++;
                dp[i][j] = min(a, b);
            }
        }
    }
    cout << dp[0][0];
}