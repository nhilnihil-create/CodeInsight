#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, m;
string s;
vector<int> sum(100100, 0);

int main() {
    cin >> n >> m >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;
    for(int i = 0; i <= n; ++i) {
        if(s.at(i) == '0') {
            sum.at(i+1) += sum.at(i) + 1;
        }else sum.at(i+1) += sum.at(i);
    }

    bool flg = true;
    for(int i = 0; i <= n; ) {
        // cout << "i " << i << endl;
        // 0にいることは保証される
        // 行けるところまで行くのが最適
        int smin = i+1; int smax = i+m;
        int exist = sum.at(min(smax+1, n+1)) - sum.at(smin);
        if(exist > 0) {
            // ここで探索をする
            for(int j = m; j >= 1; --j) {
                int snext = i+j;
                if(snext >= n) {
                    ans.emplace_back(n-i);
                    flg = false;
                    break;
                }else {
                    if(s.at(snext) == '0') {
                        i = snext;
                        ans.emplace_back(j);
                        break;
                    }
                }
            }
        }else {
            flg = false;
        }
        if(!flg) break;
    }

    int anslen = ans.size();
    int goal = 0;
    for(int i = 0; i < anslen; ++i) {
        // cout << ans.at(i) << endl;
        goal += ans.at(i);
    }

    if(goal == n) {
        for(int i = anslen-1; i >= 0; --i) {
            if(i == 0) cout << ans.at(i) << endl;
            else cout << ans.at(i) << " ";
        }
    }else cout << -1 << endl;
}