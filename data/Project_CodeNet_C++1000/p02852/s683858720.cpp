#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, M;
    string S;
    cin >> N >> M >> S;
    if (S[0] == '1') { cout << -1 << '\n'; return 0; }

    reverse(S.begin(), S.end());
    vector<int> v;
    for (int i = 0; i < N; ) {
        bool can = false;
        for (int j = M; can == false && j >= 1; j--) {
            int tmp = i+j;
            if (tmp > N) continue;
            if (S[tmp] != '1') {
                v.push_back(j);
                i += j;
                can = true;
            }
        }
        if (can == false) { cout << -1 << '\n'; return 0; }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << (i == 0 ? '\n' : ' ');
    }
}
