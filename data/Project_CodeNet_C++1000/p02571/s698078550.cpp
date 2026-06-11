#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    string S,T; cin >> S >> T;
    int ma = 0;
    int num = S.size() - T.size() + 1;

    for (int i = 0; i < num; i++) {
        int cnt = 0;
        for (int j = 0; j < T.size(); j++) {
            if (S[j+i] == T[j]) cnt++;
        }
        ma = max(ma, cnt);
    }
    cout << T.size() - ma << endl;
}