#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> Pair;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll INFL = 1e18;


int main(){
    priority_queue<int> que;
    int n,m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        que.emplace(a);
    }
    for(int i=1; i<=m; i++){
        int now = que.top();
        que.pop();
        now /= 2;
        que.emplace(now);
    }
    ll ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}