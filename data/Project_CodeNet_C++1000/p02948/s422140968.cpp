#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(100005);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.at(a).push_back(b);
    }
    ll ans = 0;
    priority_queue<int> q;
    for(int i = 1; i <= m;i++){
        for(int j = 0;j < v.at(i).size();j++) {
            q.push(v.at(i).at(j));
        }
        if(q.empty()) continue;
        ans += q.top();q.pop();
    }
    cout << ans << endl;
}