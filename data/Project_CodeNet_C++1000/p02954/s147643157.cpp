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
    vector<int> res(s.size(), 0);
    int num = 1;
    int lastR = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            res[i] += (num + 1) / 2;
            res[i+1] += num / 2;
            lastR = i;
            num = 1;
        } else if (s[i] == 'L' && s[i+1] == 'R') {
            res[lastR] += num / 2;
            res[lastR+1] += (num + 1) / 2;
            num = 1;
        } else {
            num++;
        }
    }
    res[lastR] += num / 2;
    res[lastR+1] += (num + 1) / 2;

    for (int i = 0; i < s.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}