#include<bits/stdc++.h>
#define EM 1000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, M;
    cin >> N >> M;
    int s = 1, e = M+1;
    for(;e-s > 0;) {
        cout << s << " " << e << endl;
        s++;
        e--;
    }
    s = M+2, e = 2*M+1;
    for(;e-s > 0;) {
        cout << s << " " << e << endl;
        s++;
        e--;
    }
}