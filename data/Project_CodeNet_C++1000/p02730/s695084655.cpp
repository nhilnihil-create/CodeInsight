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
    int r1 = (S.size() - 1) / 2, l2 = (S.size() + 2) / 2;
    string S1{S.begin(), S.begin() + r1}, S2{S.begin() + l2, S.end()};

    string revS = S, revS1 = S1, revS2 = S2;
    reverse(revS.begin(), revS.end()); reverse(revS1.begin(), revS1.end()); reverse(revS2.begin(), revS2.end());

    if (S == revS && S1 == revS1 && S2 == revS2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
