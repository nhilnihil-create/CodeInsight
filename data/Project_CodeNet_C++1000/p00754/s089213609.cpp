#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

bool check(string s) {
    stack<char> stk;
    stk.push('#');
    for (auto c : s) {
        if (c == '(' || c == '[') {
            stk.push(c);
        } else if (c == ')' || c == ']') {
            if ((stk.top() == '(' && c == ')') || (stk.top() == '[' && c == ']')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.size() == 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    while (getline(cin, s), s[0] != '.') {
        cout << (check(s) ? "yes" : "no") << endl;
    }
}