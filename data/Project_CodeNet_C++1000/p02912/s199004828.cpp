#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstring>
#include<string>
#include<set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll = long long int;

const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void) {
    int n, m; cin >> n >> m;
    priority_queue<int> pque;
    REP(i, n) {
        int a; cin >> a;
        pque.push(a);
    }
    REP(i, m) {
        int top = pque.top();
        pque.pop();
        top /= 2;
        pque.push(top);
    }
    ll sum = 0;
    while (!pque.empty()) {
        int tmp = pque.top();
        pque.pop();
        sum += tmp;
    }
    cout << sum << endl;
}