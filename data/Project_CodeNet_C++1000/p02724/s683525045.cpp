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
    ll N;
    cin >> N;
    ll m1 = (N / 500) * 1000 + ((N % 500) / 5) * 5;
    ll m2 = (N / 5) * 5;
    cout << max(m1, m2) << '\n';
}
