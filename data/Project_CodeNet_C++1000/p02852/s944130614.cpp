//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    reverse(all(s));
    stack<int> ans;

    rep(i, n) {
        int j = min(m, n-i);
        while(1) {
            if(s[i+j] == '0') {
                ans.push(j);
                i = i+j-1;
                break;
            }
            j--;
            if(!j) {
                ans.push(-1);
                i = n-1;
                break;
            }
        }
    }

    if(ans.top() == -1) {
        cout << -1 << endl;
    } else {
        while(!ans.empty()) {
            int now = ans.top();
            ans.pop();

            cout << now << (ans.empty() ? '\n':' ');
        }
    }
}