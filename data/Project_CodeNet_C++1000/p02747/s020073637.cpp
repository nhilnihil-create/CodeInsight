#include <algorithm>
#include <iostream>
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

int main(void) {
    string S;
    cin >> S;

    if (((int) S.size()) % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }

    bool b = true;
    bool ok = true;

    for (auto &c : S) {
        if (b) {
            if (c != 'h') {
                ok = false;
                break;
            }
        } else {
            if (c != 'i') {
                ok = false;
                break;
            }
        }

        b = !b;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
