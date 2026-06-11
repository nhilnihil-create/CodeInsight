#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    string t;
    cin >> t;

    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '?') {
            t[i] = 'D';
        }
    }
    cout << t << endl;
}