#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    set<int> check, tmp;
    queue<int> que[N];
    rep(i, N){
        rep(j, N-1){
            int A; cin >> A; A--;
            que[i].push(A);
        }
        check.insert(i);
    }
    while(true){
        for(auto &e: check){
            if(que[e].empty()) continue;
            int j = que[e].front();
            if(que[j].front() == e){
                tmp.insert(e), tmp.insert(j);
            }
        }
        for(auto &e: tmp) que[e].pop();
        check.clear();
        swap(check, tmp);
        if(!check.empty()) cnt++;
        else break;
    }
    rep(i, N){
        if(!que[i].empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
}