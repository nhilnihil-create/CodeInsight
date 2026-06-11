#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    string s; cin >> s;
    // RRLRL -> 0 1 2 1 1
    // RRLLLLRLRRLL -> 0 3 3 0 0 0 1 1 0 2 2 0
    // RRRLLRLLRRRLLLLL -> 0 0 3 2 0 2 1 0 0 0 4 4 0 0 0 0

    // 初期値がRかLかで分岐
    // Rであれば右にRLが見つかるまで進み、Lであれば左にRLが見つかるまで進む
    // RLの中では偶奇で分岐する

    // RRLRLについて個別に考える
    // 0: より右で最初のRLの始まりは1。1->2->1->2->...->2に落ち着く
    // 1: より右で最初のRLの始まりは1。2->1->2->1->...->1に落ち着く
    // 2: より左で最初のRLの始まりは1。1->...->1
    // 3: より右で最初のは3。3->4->3...->4に落ち着く

    // RLの開始位置を確認
    bool rl[100001];
    REP(i, s.size()-1) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            rl[i] = true;
        }
    }

    // より右のrl始点、より左のrl始点を確認
    ll right[100001];
    ll left[100001];
    ll tmp = -1;
    FORD(i, s.size()-1, 0) {
        if (i <= s.size()-2 && s[i] == 'R' && s[i+1] == 'L') {
            tmp = i;
        }
        right[i] = tmp;
    }
    FOR(i, 0, s.size()-1) {
        if (i <= s.size()-2 && s[i] == 'R' && s[i+1] == 'L') {
            tmp = i;
        }
        left[i] = tmp;
    }

    // それぞれの個数確認
    ll res[100001]; INITA(res, 0, 100000, 0);
    REP(i, s.size()) {
        // cout << i << " " << s[i] << " " << rl[i] << " " << right[i] << " " << left[i] << endl;
        if (s[i] == 'R') {
            if ((right[i] - i) % 2 == 0) {
                res[right[i]]++;
            } else {
                res[right[i]+1]++;
            }
        } else {
            if ((i-left[i]) % 2 == 0) {
                res[left[i]]++;
            } else {
                res[left[i]+1]++;
            }
        }
    }

    REP(i, s.size()) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;

    return 0;
}