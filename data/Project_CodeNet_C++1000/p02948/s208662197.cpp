#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

vector<int> q[101010];

int main() {
    int n,m;
    cin>>n>>m;
    
    vector<int> a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        q[a[i]].push_back(b[i]);
    }

    priority_queue<int> que;
    int ans=0;
    for(int i=1;i<m+1;i++){
        for(auto e : q[i]) que.push(e);
        if(!que.empty()){
            ans+=que.top();
            que.pop();
        }
    }

    cout<<ans<<endl;
}