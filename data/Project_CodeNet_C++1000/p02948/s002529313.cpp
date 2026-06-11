#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<int> q[101010];

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,n) q[a[i]].push_back(b[i]);

    priority_queue<int> que;
    int ans=0;
    for(int i=1;i<m+1;i++){
        for(auto b : q[i]) que.push(b);
        if(!que.empty()){
            ans+=que.top();
            que.pop();
        }
    }

    cout<<ans<<endl;
}


 