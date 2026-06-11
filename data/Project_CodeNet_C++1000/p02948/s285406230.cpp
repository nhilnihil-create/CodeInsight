#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<int> to[100010];
int main(){
    cout << fixed << setprecision(10);
    int n,m;
    cin >> n >> m;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        to[a].push_back(b);
    }
    int ans = 0;
    priority_queue<int> que;
    rep(i,m){
        for(auto u : to[i+1]){
            que.push(u);
        }
        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}