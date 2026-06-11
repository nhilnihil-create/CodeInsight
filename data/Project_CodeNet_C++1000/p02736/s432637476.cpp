#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int getOdd(const vector<int>& A) {
    int N = (int)A.size();
    int cnt0 = 0;
    rep(i, 1, N) {
        int now = i;
        while (now % 2 == 0) {
            ++cnt0;
            now /= 2;
        }
    }
    int cnt1 = cnt0, cnt2 = 0;
    int odd = 0;
    rep(i, 0, N) {
        if (A[i] % 2) {
            if (cnt0 == cnt1 + cnt2) {
                odd ^= 1;
            }
        }
        int now = N - i - 1;
        while (now > 0 && now % 2 == 0) {
            --cnt1;
            now /= 2;
        }
        now = i + 1;
        while (now % 2 == 0) {
            ++cnt2;
            now /= 2;
        }
    }
    return odd;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, 0, N) {
        A[i] = (int)(S[i] - '0') - 1;
    }
    if (getOdd(A)) {
        cout << 1 << endl;
        return 0;
    }
    for (auto& a : A) {
        if (a == 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (auto& a : A) {
        a /= 2;
    }
    if (getOdd(A)) {
        cout << 2 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}