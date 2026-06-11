#include<iostream>
#include<vector>
#include<string>
#include<set>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

void dfs(int N, string& S) {
    if (N == (int)S.size()) {
        cout << S << endl;
        return;
    }
    set<char> cnt;
    for (auto& c : S) {
        cnt.insert(c);
    }
    for (auto& c : cnt) {
        S += c;
        dfs(N, S);
        S.pop_back();
    }
    S += *cnt.rbegin() + 1;
    dfs(N, S);
    S.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string S = "a";
    dfs(N, S);
    return 0;
}