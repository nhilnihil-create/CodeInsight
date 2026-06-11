#include <bits/stdc++.h>
using namespace::std;
#define int long long

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sax(x) cout << "!!!!!!!!!!! " << #x << " = " << x << '\n'
#define inf (sizeof(int) == 4 ? (int)1E9 : (int)1E18)
#define one(x) x.insert(x.begin(), 0);
#define TCT template <class T>
#define TCT12 template <class T1, class T2>
#define IS istream
#define OS ostream
#define OP operator

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
//tree_order_statistics_node_update> imsi;

TCT IS& OP>>(IS &I, vector<T>& v) {for (T &e: v) I >> e; return I;}
TCT OS& OP<<(OS &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; /*O << '\n';*/ return O;}
TCT OS& OP<<(OS &O, const unordered_set<T>& v) {for (const T &e: v) O << e << ' '; return O;}
TCT OS& OP<<(OS &O, const set<T>& v) {for (const T &e: v) O << e << ' '; return O;}
TCT OS& OP<<(OS &O, const unordered_multiset<T>& v) {for (const T &e: v) O << e << ' '; return O;}
TCT OS& OP<<(OS &O, const multiset<T>& v) {for (const T &e: v) O << e << ' '; return O;}
TCT IS& OP>>(IS &I, deque<T>& v) {for (T &e: v) I >> e; return I;}
TCT OS& OP<<(OS &O, const deque<T>& v) {for (const T &e: v) O << e << ' '; return O;}
TCT OS& OP<<(OS &O, priority_queue<T> v) {while (!v.empty()) {O << v.top() << ' '; v.pop();} return O;}
TCT OS& OP<<(OS &O, stack<T> v) {while (!v.empty()) {O << v.top() << '\n'; v.pop();} return O;}
TCT OS& OP<<(OS &O, queue<T> v) {while (!v.empty()) {O << v.front() << ' '; v.pop();} return O;}
TCT12 IS& OP>>(IS &I, pair<T1,T2>& p) {return I >> p.first >> p.second;}
TCT12 OS& OP<<(OS &O, const pair<T1,T2>& p) {return O << '(' << p.first << ' ' << p.second << ')';}
TCT12 OS& OP<<(OS &O, const unordered_map<T1,T2>& v) {for (const auto &e: v) O << e << ' '; return O;}
TCT12 OS& OP<<(OS &O, const map<T1,T2>& v) {for (const auto &e: v) O << e << ' '; return O;}
typedef pair<int,int> pii;
typedef vector<int> vi;


//RRRRRRRRL
//

void _main() {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        for (const auto t: {"LR", "RL"}) {
                for (const auto sgn: {-1, 1}) {
                        string str = s;
                        priority_queue<tuple<int,int,int>> pq;
                        char p = t[0], q = t[1];
                        for (int i = 0, j; i < n; i++) {
                                if (str[i] == q) {
                                        j = i;
                                        int cost = 0;
                                        while (j < n && str[j] == q) {
                                                j++;
                                                if (p == 'L') {
                                                        if (j && str[j - 1] == 'L') cost++;
                                                } else {
                                                        if (j + 1 < n && str[j + 1] == 'R') cost++;
                                                }
                                        }
                                        pq.emplace(cost, sgn * (p == 'L' ? i : -i), j - 1);
                                        i = j - 1;
                                }
                        }

                        //RRRLLLLLL
                        //RRRLRLRLL
                        int y = k;
                        while (y-- && pq.size()) {
                                int x, i, j;
                                tie(x, i, j) = pq.top(); pq.pop();
                                for (int ii = abs(i); ii <= j; ii++) {
                                        str[ii] = p;
                                }
                        }

                        int cnt = 0;
                        for (int i = 0; i < n; i++) {
                                if (str[i] == 'L') {
                                        if (i && str[i - 1] == 'L') cnt++;
                                } else {
                                        if (i + 1 < n && str[i + 1] == 'R') cnt++;
                                }
                        }


                        ans = max(ans, cnt);
                }
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
