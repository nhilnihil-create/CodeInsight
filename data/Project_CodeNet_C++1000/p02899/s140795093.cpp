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
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        p[a-1] = i+1;
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << p[i];
    }
    cout << '\n';
}
