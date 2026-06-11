#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    priority_queue<P, vector<P>, greater<P>> q;
    priority_queue<int> p;
    rep(i, n){
        int a, b; cin >> a >> b;
        q.push(make_pair(a, b));
    }

    ll ans = 0;
    for(int i=1; i<=m; i++){
        while(q.top().first<=i && !q.empty()){
            p.push(q.top().second);
            q.pop();
            if(q.empty()){
                break;
            }
        }

        if(!p.empty()) {
            ans += p.top();
            p.pop();
        }
        dump(ans);
    }

    cout << ans << endl;
    return 0;
}
