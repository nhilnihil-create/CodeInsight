#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 1 && s[i] == 'R') flag = false;
        if (i % 2 == 0 && s[i] == 'L') flag = false;
    }
    cout << (flag ? "Yes" : "No") << endl;
}