#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(obj) obj.begin(), obj.end()

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int main() { 
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i += 2) {
        if (S[i] == 'h' && S[i + 1] == 'i') {
            
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0; 
}