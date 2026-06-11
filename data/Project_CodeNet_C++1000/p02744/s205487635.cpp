#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

char calc_max_c(const string &s) {
    char ans = 'a';
    for (auto &c : s) {
        chmax(ans, c);
    }
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    vector<string> as;
    as.push_back("a");

    for (int i = 1; i < N; i++) {
        vector<string> old;
        swap(as, old);
        for (auto & s : old) {
            char max_c = calc_max_c(s);
            for (char c = 'a'; c <= max_c + 1; c++) {
                as.push_back(s + c);
            }
        }
    }

    for (auto &a : as) {
        cout << a << endl;
    }

    return 0;
}
