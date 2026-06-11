#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, S[2 << 18];
int M;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
    map<int, int> cnt;
    rep(i, 0, M) cnt[S[i]]++;
    vector<pair<int,int>> v;
    fore(p, cnt) v.push_back(p);
    sort(all(v), greater<pair<int, int>>());

    priority_queue<int> connection;
    connection.push(M);
    fore(p, v)
    {
        int cnt = p.second;
        if(connection.size() < cnt)
            return no;

        vector<int> buf;
        rep(i, 0, cnt) {
            buf.push_back(connection.top());
            connection.pop();
        }

        fore(c, buf) {
            c /= 2;
            while (0 < c)
            {
                connection.push(c);
                c /= 2;
            }
        }
    }

    return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    M = 1;
    rep(i, 0, N) M *= 2;
    rep(i, 0, M) cin >> S[i];

    cout << solve() << endl;
}

