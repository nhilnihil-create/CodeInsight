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
int N;
vector<string> v;
/* function */
void rec(int n, string s) {
    if (s.size() == N) {
        v.push_back(s);
        return ;
    }
    for (int i = 1; i <= n+1; i++) {
        string t;
        t += static_cast<char>('a' + i - 1);
        rec((i == n+1) ? n+1 : n, s + t);
    }
}
/* main */
int main(){
    cin >> N;
    rec(1, "a");
    sort(v.begin(), v.end());
    for (string s : v) cout << s << '\n';
}
