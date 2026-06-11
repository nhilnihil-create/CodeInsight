#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
    int n,k;
    cin >> n >> k;
    
    vv connect(n);
    int a,b;
    rep(i,n-1){
        cin >> a >> b;
        a--;b--;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    
    v reach(n,0);
    
    ll ans = 1;
    
    queue<int> q;
    q.push(0);
    reach[0] = 1;
    ans *= k;
    
    int ane=0;
    for(auto d: connect[q.front()]){
        if(reach[d])continue;
        reach[d] = 1;
        q.push(d);
        ans *= k - ane - 1;
        ans %= MOD;
        ane++;
    }
    q.pop();
    
    while(!q.empty()){
        int now = q.front();
        ane=0;
        for(auto d: connect[now]){
            if(reach[d])continue;
            reach[d] = 1;
            q.push(d);
            ans *= k - ane - 2;
            ans %= MOD;
            ane++;
        }
        q.pop();
    }
    cout << ans << endl;
    
    return 0;
}