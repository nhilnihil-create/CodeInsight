#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> jobs(m);
    rep(i,0,n){
        int a, b;
        cin >> a >> b;
        if(m < a) continue;
        jobs[a-1].push_back(b);
    }
    priority_queue<int> q;
    ll ans = 0;
    rep(i,0,m) {
        for(int j: jobs[i]){
            q.push(j);
        }
        if(q.empty()) continue;
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
