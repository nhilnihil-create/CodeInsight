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
    string S;
    cin >> S;
    // v[0] = head, v[1] = tail
    vector<string> v(2, "");
    int Q;
    cin >> Q;
    int rev = 0;
    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if (T == 1) rev = (rev + 1) % 2;
        else {
            int F;
            string C;
            cin >> F >> C;
            F--;
            // F == 0 -> head, F == 1 -> tail
            v[(F + rev) % 2] += C;
        }
    }

    reverse(v[rev].begin(), v[rev].end());
    if (rev == 0) { cout << v[0] << S << v[1] << '\n'; }
    else {
        reverse(S.begin(), S.end());
        cout << v[1] << S << v[0] << '\n';
    }
}
