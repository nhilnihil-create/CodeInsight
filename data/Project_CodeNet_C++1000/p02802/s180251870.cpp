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
    cin >> N >> M;
    int cntAC = 0, cntWA = 0;
    vector<int> isAC(N+1, 0);
    vector<int> WA(N+1, 0);
    for (int i = 0; i < M; i++) {
        int num;
        string S;
        cin >> num >> S;
        if (isAC[num]) continue;
        if (S == "AC") {
            cntAC++;
            isAC[num] = 1;
            cntWA += WA[num];
        }
        else WA[num]++;
    }
    cout << cntAC << ' ' << cntWA << '\n';
}
