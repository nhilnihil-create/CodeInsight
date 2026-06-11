#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    int N, K; cin >> N >> K;
    int R, S, P; cin >> R >> S >> P;
    string T; cin >> T;
    vector<vector<char>> t(K);
    for (int i = 0; i < N; i++) {
        int m = i % K;
        t.at(m).push_back(T.at(i));
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        char prev = 'n';
        for (int j = 0; j < t.at(i).size(); j++) {
            if (t.at(i).at(j) != prev) {
                if (t.at(i).at(j) == 'r') {
                    ans += P;
                    prev = 'r';
                }
                else if (t.at(i).at(j) == 's') {
                    ans += R;
                    prev = 's';
                }
                else {
                    ans += S;
                    prev = 'p';
                }
            }
            else {
                if (j < t.at(i).size() - 1) {
                    if (t.at(i).at(j + 1) == 'r') {
                        prev = 's';
                    }
                    else if (t.at(i).at(j + 1) == 's') {
                        prev = 'p';
                    }
                    else {
                        prev = 'r';
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}