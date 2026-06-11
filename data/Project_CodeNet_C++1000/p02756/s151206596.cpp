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
    int Q;
    cin >> S >> Q;
    string Sf = "", Sb = "";
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 1) cnt++;
        else {
            int f; string Sin;
            cin >> f >> Sin;
            if (cnt % 2) {
                reverse(Sin.begin(), Sin.end());
                if (f == 1) Sb += Sin;
                else Sf = Sin + Sf;
            }
            else {
                if (f == 1) Sf = Sin + Sf;
                else Sb += Sin;
            }
        }
    }
    if (cnt % 2) {
        reverse(Sb.begin(), Sb.end());
        reverse(S.begin(), S.end());
        reverse(Sf.begin(), Sf.end());
        cout << Sb << S << Sf << '\n';
    }
    else cout << Sf << S << Sb << '\n';
}
