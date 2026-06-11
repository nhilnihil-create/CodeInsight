#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;


    bool ok = true;
    int num1 = 0;
    rep (i, n + 1) {
        if (s[i] == '0') {
            num1 = 0;
            continue;
        }
        if (s[i] == '1') num1++;
        if (num1 >= m) ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    
    int startPos = n;
    int nowPos = n;
    nowPos -= m;
    bool fir = false;

    vector<int> ans;
    for (; startPos > 0; ) {
        if (nowPos < 0) {
            nowPos++;
            continue;
        }

        if (s[nowPos] == '0') {
            ans.pb(startPos - nowPos);
            startPos = nowPos;
            nowPos -= m;
            fir = true;
        }
        else {
            nowPos++;
            fir = false;
        }

    }

    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;
    return 0;
}