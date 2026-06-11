#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

int main(void) {
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    vector<char> ls;
    vector<char> rs;
    for (auto c : S) {
        rs.push_back(c);
    }

    int dir = 1;

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            dir *= -1;
        } else {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1) {
                if (dir == 1) {
                    ls.push_back(c);
                } else {
                    rs.push_back(c);
                }
            } else {
                if (dir == 1) {
                    rs.push_back(c);
                } else {
                    ls.push_back(c);
                }
            }
        }
    }

    vector<char> new_ls = (dir == 1) ? move(ls) : move(rs);
    vector<char> new_rs = (dir == 1) ? move(rs) : move(ls);

    for (int i = (int) new_ls.size() - 1; i >= 0; i--) {
        cout<< new_ls[i];
    }
    for (int i = 0; i < (int) (new_rs).size(); i++) {
        cout << new_rs[i];
    }
    cout << endl;

    return 0;
}
