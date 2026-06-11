#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int k;
    cin >> k;
    priority_queue<ll, vector<ll>, greater<ll>> que;

    for (int i = 1; i < 10; ++i) {
        que.push(i);
    }

    ll run;
    while(1){
        run = que.top();
        que.pop();
        k--;
        if (k == 0){
            cout << run << endl;
            return 0;
        }
        que.push(run * 10 + run % 10);
        if (run % 10 > 0) que.push(run * 10 + run % 10 - 1);
        if (run % 10 < 9) que.push(run * 10 + run % 10 + 1);
    }
}