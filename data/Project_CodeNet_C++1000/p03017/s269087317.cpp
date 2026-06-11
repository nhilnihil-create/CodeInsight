#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

string s; 
int n, c, d;
map<P,bool> memo;

bool dfs(int now, int g) {
    if (now == g) return true;
    if (now > g) return false;
    bool res = false;
    if (s[now+1] != '#' && dfs(now+1,g)) res = true;
    if (s[now+2] != '#' && dfs(now+2,g)) res = true;
    return res;
}

int main() {
    int a, b; 
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;
    if (c < d) {
        if (dfs(a,c) && dfs(b,d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        for (int i = b; i <= d; i++) {
            if (s[i-1] == '#' || s[i] == '#' || s[i+1] == '#') continue;
            if (dfs(a,i-1) && dfs(b,i) && dfs(a+1,c) && dfs(b,d)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }

}