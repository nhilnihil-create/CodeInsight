#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(ALL(s));

    // mem : '1'の最大連続数
    ll mem = 0, b = 0;
    vll a(n + 1);
    REP(i, n + 1) {
        a[i] = int(s[i] - '0');
        if (a[i] == 1) b++;
        else {
            chmax(mem, b);
            b = 0;
        }
    }

    // 到達不可能
    if (mem >= m) {
        cout << -1 << endl;
        return 0;
    }

    // res : 各ターンで出すべき目
    // cur : 現在地
    vll res;
    ll cur = 0;

    while (cur != n) {
        // dice : このターン出すべき目
        ll dice = min(m, n - cur);
        while (a[cur + dice] != 0) dice--;
        cur += dice;
        res.push_back(dice);
    }
    reverse(ALL(res));
    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}