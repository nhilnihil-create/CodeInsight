#include <bits/stdc++.h>
#include <vector>
using namespace std;
using Graph = vector<vector<bool>>;

typedef long long ll;

const ll MAX = 110000;
const ll INF = 1LL << 60;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline long long factorial(T N) {
    int ans = 1;
    for (int i = 1; i <= N; ++i) {
        ans *= i;
    }
    return ans;
}


int main() {
    string S, T; cin >> S >> T;
    int count = 0;
    for (int i =0; i < 3; ++i) {
        if (S[i] == T[i]) {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
