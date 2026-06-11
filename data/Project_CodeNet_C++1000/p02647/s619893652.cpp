#include<iostream>
#include<vector>
#include<string>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

vector<int> change(int N, const vector<int>& A) {
    vector<int> res(N, 0);
    rep(i, 0, N) {
        ++res[max(0, i - A[i])];
        if (i + A[i] + 1 < N) {
            --res[i + A[i] + 1];
        }
    }
    rep(i, 1, N) {
        res[i] += res[i - 1];
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    rep(i, 0, K) {
        vector<int> B = change(N, A);
        if (A == B) {
            break;
        }
        swap(A, B);
    }
    rep(i, 0, N) {
        cout << A[i] << " \n"[i + 1 == N];
    }
    return 0;
}