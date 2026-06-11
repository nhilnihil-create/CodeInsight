#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e17;
// https://atcoder.jp/contests/abc143/submissions/8034843

int main() {
    // input
    int N;
    cin >> N;

    // 偶数
    if (N%2 ==0)
    {
        cout << N/2-1 << endl;
    }
    else
    {
        cout << N/2 << endl;
    }

    return 0;
}
